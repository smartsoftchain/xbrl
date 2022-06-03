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

class index extends base_model_ambiguous {

  //処理
  public function execute() {

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

    // 表示させる項目
    $smarty->set("login_error", false);
    if($this->is_bag("login_error")){
      if(0 != count($_POST)){
        $smarty->set("login_error", $this->get_bag("login_error"));
      }
    }
    
  }

} // end of class


