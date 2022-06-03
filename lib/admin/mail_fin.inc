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

class mail_fin extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    
    $id = $req->find("id");
    $mail = $this->get_clump("mail_template_clump");
    $mail->set_value("id", $id);
    if($mail->get()){
      $mail->set_from_cgi($req);
      $mail->set();
    }

    $this->redirect("admin.php?c=admin_mail");
    return ;
  }
} // end of class


