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

class ignore_list extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    

    //
    $sql = "select financial_code, name, created_at, reopen_at from ignore_list order by financial_code asc";
    $res = $db->query($sql);
    $datum = array();
    while($res->fetch()){
      $tmp = array();
      $tmp["financial_code"] = $res->get_data(0);
      $tmp["name"] = $res->get_data(1);
      $tmp["created_at"] = $res->get_data(2);
      $tmp["reopen_at"] = $res->get_data(3);
      $datum[] = $tmp;
    }

    $smarty->set("datum", $datum);
    return ;
  }
} // end of class


