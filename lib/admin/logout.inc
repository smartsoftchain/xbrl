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

class logout extends base_model_ambiguous {

  //処理
  public function execute() {
    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

    setcookie("sid", "", time()-1000);

    $this->redirect("admin.php");
    return;
  }

} // end of class


