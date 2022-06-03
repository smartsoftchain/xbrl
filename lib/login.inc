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

require_once("common/auth.inc");

class login extends base_model_ambiguous {

  //処理
  public function execute() {
    $this->authentics();

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

    $id = $req->find("id");
    $pw = $req->find("pw");

    $auth = new auth;
    $auth->set_conf($this->get_config());
    $auth->set_db($db);

    $ret = $auth->login($id, md5($pw));

    $this->recursive_on();
    if(false == $ret){
      $this->set_recursive_command("index");
      $this->set_bag("login_error", true);
    }else{
      $this->set_recursive_command("top");
    }

    return;
  }

} // end of class


