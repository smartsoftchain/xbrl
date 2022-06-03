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
require_once("authentication_password_stretching.inc");

class info_fin extends base_model_admin_base {

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
    $pass_raw = $req->find("pass_raw");
    if(!empty($id) && !empty($pass_raw)){
      $make = new authentication_password_stretching;
      $pass = $make->stretching($id, $pass_raw);

      $sql = "delete from auth_admin_user";
      $db->query($sql);

      $admin = $this->get_clump("auth_admin_user_clump");
      $admin->set_value("id", $id);
      $admin->set_value("pass", $pass);
      $admin->set_value("pass_raw", $pass_raw);
      $admin->set();
    }
    $this->redirect("admin.php");
    return ;
  }
} // end of class


