<?php

/***************************************************
 * ログイン後トップ画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('base_model_admin_base.inc');
require_once("calendar.inc");

class ignore_list_fin extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    

    //
    $code = $req->find("financial_code");
    $date = $req->find("created_at");
    $reopen = $req->find("reopen_at");

    if("" == $reopen){
      $cal = new calendar;
      $cal->set_now_date();
      $cal->calculation_month(3);
      $reopen = date("Y-m-d", $cal->get_epoc());
    }

    $sql = "select company_name from daily_financial_price where financial_code = '". $code."' limit 1";
    $res = $db->query($sql);
    $name = "";
    if($res->fetch()){
      $name = $res->get_data(0);
    }

    if("" != $name){
      $clump = $this->get_clump("ignore_list_clump");
      $clump->set_value("financial_code", $code);
      $clump->set_value("name", $name);
      $clump->set_value("reopen_at", $reopen);
      if("" != $date){
        $clump->set_value("created_at", $date);
      }else{
        $clump->set_value_nowdate("created_at");
      }
      $clump->set();
    }

    $this->redirect("admin.php?c=ignore_list");
    return ;
  }
} // end of class


