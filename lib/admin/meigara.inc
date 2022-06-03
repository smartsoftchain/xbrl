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

class meigara extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    

    // 本日
    $sql = "select financial_code, name, market_flg, created_at from meigara order by financial_code";
    $res = $db->query($sql);
    $datum = array();

    while($res->fetch()){
      $tmp = array();
      $tmp["financial_code"] = $res->get_data(0);
      $tmp["name"] = $res->get_data(1);
      $tmp["market_flg"] = $res->get_data(2);
      $tmp["created_at"] = $res->get_data(3);
      $datum[] = $tmp;
    }

    $smarty->set("datum", $datum);
    return ;
  }
} // end of class


