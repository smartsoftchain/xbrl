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

require_once('common/base_model_front_base.inc');
require_once("common/util.inc");

class calc extends base_model_front_base {

  //処理
  public function execute() {
    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();



  }

} // end of class


