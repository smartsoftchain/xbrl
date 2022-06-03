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

  class clip extends base_model_ambiguous {

  //処理
  public function execute() {
    parent::execute();

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

    // 表示させる項目
    $mode = $req->find("mode");
    
    $user = $this->get_user_info();

    if("add" == $mode){
      $clip = $this->get_clump("clip_clump");
      $clip->set_value("user_id", $user->get_value("id"));
      $clip->set_value("financial_code", $req->find("financial_code"));
      $clip->set_value("scene", $req->find("scene"));
      $clip->set_value_nowdate("created_at");
      $clip->set();
    }else
    if("del" == $mode){
      $clip = $this->get_clump("clip_clump");
      $clip->set_value("user_id", $user->get_value("id"));
      $clip->set_value("financial_code", $req->find("financial_code"));
      if($clip->get()){
        $clip->del();
      }
    }
    $this->redirect("index.php?c=". $req->find("ret"));
    return;
  }

} // end of class


