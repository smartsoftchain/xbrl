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

class user_info_fin extends base_model_ambiguous {

  //処理
  public function execute() {
    parent::execute();

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

    // 表示させる項目
    $user = $this->get_user_info();
    $sql = "select count(id) from user where id != ". $user->get_value("id"). " and mail = '". $req->find("mail")."'";
    $res = $db->query($sql);
    $count = 0;
    if($res->fetch()){
      if(0 == $res->get_data(0)){
        $user->set_value("name", $req->find("name"));
        $user->set_value("mail", $req->find("mail"));
        $user->set_value("pass", $req->find("pass"));
        $user->set();
      }
    }

    $this->redirect("index.php?c=user_info");
    return;
  }

} // end of class


