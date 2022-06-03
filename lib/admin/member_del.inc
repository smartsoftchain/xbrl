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

class member_del extends base_model_admin_base {

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

    $id = $req->find("id");
    $user = $this->get_clump("user_clump");
    $user->set_value("id", $id);
    $user->get();
    $user->del();

    $this->redirect("admin.php?c=top");
 

    return ;
  }
} // end of class


