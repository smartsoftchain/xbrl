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

class newmember_post extends base_model_ambiguous {

  //処理
  public function execute() {

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

    $name = $req->find("name");
    $mail = $req->find("mail");
    $pass = $req->find("pass");

    $result = false;

    // 表示させる項目
    if(!empty($name)||!empty($mail)||!empty($pass)){
      $user = $this->get_clump("user_clump");
      $user->set_value("name", $name);
      $user->set_value("mail", $mail);
      $user->set_value("pass", $pass);
      $user->get_nopk();

      if("" == $user->get_value("id")){
        $user->set_value_nowdate("update_date");
        $user->set();
        $result = true;
        $smarty->set("user", $user);
      }
    }
    $smarty->set("result", $result);
  }

} // end of class


