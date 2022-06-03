<?php

/***************************************************
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_ambiguous.inc');
require_once('common/util.inc');

class password_fin extends base_model_ambiguous {

  //処理
  public function execute() {
    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

    // 表示させる項目
    $user = $this->get_clump("user_clump");
    $user->set_value("mail", $req->find("mail"));
    $user->get_nopk();
    if("" != $user->get_value("id")){
      $mail = $this->get_clump("mail_template_clump");
      $mail->set_value("id", 3);
      $mail->get();

      $mailfrom="From:" .mb_encode_mimeheader($mail->get_value("from_name")) ."<". $mail->get_value("from_address"). ">";
      $body = $mail->get_value("body");
      $body = mb_ereg_replace("%%%name%%%", $user->get_value("name"), $body);
      $body = mb_ereg_replace("%%%password%%%", $user->get_value("pass"), $body);

      mb_send_mail($user->get_value("mail"), $mail->get_value("subject"), $body, $mailfrom);
    }

    return;
  }

} // end of class


