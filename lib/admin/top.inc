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
require_once("page_controll_limit.inc");

class top extends base_model_admin_base {

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

    $p = $req->find("p") + 0;
    $sql = "select id from user ";

    $page = new page_controll_limit;
    $page->set_db($db);
    $page->set_sql($sql);
    $page->set_page_num($p);
    $page->set_par_item_num(10);
    $page->make_list();

    $ids = $page->get_list();
    $smarty->set("page", $page);
    $smarty->set("now_page", $page->get_page_num());

    $users = array();
    foreach($ids as $id){
      $user = $this->get_clump("user_clump");
      $user->set_value("id", $id);
      if($user->get()){
        $users[] = $user;
      }
    }
    $smarty->set("users", $users);

    return ;
  }
} // end of class


