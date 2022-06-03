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

class ignore_list_del extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    

    //
    $code = $req->find("code");

    if("" != $code){
      $clump = $this->get_clump("ignore_list_clump");
      $clump->set_value("financial_code", $code);
      if($clump->get()){
        $clump->del();
      }
    }

    $this->redirect("admin.php?c=ignore_list");
    return ;
  }
} // end of class


