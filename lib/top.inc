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

class top extends base_model_ambiguous {

  //処理
  public function execute() {
    parent::execute();

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();

    // 表示させる項目
    $smarty->set("member", $this->get_user_info());

    $db = $this->get_data_db();
    $sql = "select max(created_at) from search_focus";
    $res = $db->query($sql);
    $cal = new calendar;
    $cal->set_now_date();
    if($res->fetch()){
      $last_date = $res->get_data(0);
      $cal->set_string($last_date);
    }

    $smarty->set("last_date", date("Y年m月d日 H時i分", $cal->get_epoc()));
  }

} // end of class


