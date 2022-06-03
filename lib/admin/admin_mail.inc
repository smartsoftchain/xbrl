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

class admin_mail extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    

    // 本日
    $cal = new calendar;
    $cal->set_now_date();
    $now_epoc = $cal->get_epoc();

    $buy = $this->get_clump("mail_template_clump");
    $buy->set_value("id", 1);
    $buy->get();
    $smarty->set("buy", $buy->get_all_data_to_hash());

    $sell = $this->get_clump("mail_template_clump");
    $sell->set_value("id", 2);
    $sell->get();
    $smarty->set("sell", $sell->get_all_data_to_hash());

    $pr = $this->get_clump("mail_template_clump");
    $pr->set_value("id", 3);
    $pr->get();
    $smarty->set("pr", $pr->get_all_data_to_hash());


    return ;
  }
} // end of class


