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

class info extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    

    // 本日
    $cal = new calendar;
    $cal->set_now_date();
    $now_epoc = $cal->get_epoc();

    $sql = "select id,pass_raw from auth_admin_user";
    $res = $db->query($sql);
    if($res->fetch()){
      $smarty->set("id", $res->get_data(0));
      $smarty->set("pass_raw", $res->get_data(1));
    }
    return ;
  }
} // end of class


