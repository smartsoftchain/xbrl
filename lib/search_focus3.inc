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

class search_focus3 extends base_model_ambiguous {

  //処理
  public function execute() {
    parent::execute();

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_db();

/*
    // 表示させる項目
    $sql = "select max(trade_date) from financial_status";
    $res = $db->query($sql);
    if($res->fetch()){
      $max_date = $res->get_data(0);
    }

    $sql = "select id from financial_status where status = 4 and trade_date = '". $max_date."' order by financial_code asc";
    $res = $db->query($sql);
    
    $cal = new calendar;
    $cal->set_now_date();

    $user = $this->get_user_info();

    $datum = array();
    while($res->fetch()){
      $financial_id = $res->get_data(0);
      $status = $this->get_clump("financial_status_clump");
      $status->set_value("id", $financial_id);
      $status->get();

      if(in_array($status->get_value("financial_code"), $this->get_ignore_list())){ continue; }
      $daily = $this->get_clump("daily_financial_price_clump");
      $daily->set_value("trade_date", $status->get_value("trade_date"));
      $daily->set_value("financial_code", $status->get_value("financial_code"));
      $daily->get();
      if("--unregistered--" == $daily->get_value("company_name")){
//        continue;
      }
      if($daily->get_value("end_price") == 0){
        continue;
      }

      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date < '". $max_date."' order by trade_date desc limit 1";
      $res2 = $this->get_db()->query($sql);
      $bk=1;
      if($res2->fetch()){
        $bk = $res2->get_data(0);
      }
      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date = '". $status->get_value("status_3_date")."' order by trade_date desc limit 1";
      $res3 = $this->get_db()->query($sql);
      $status3_price = 0;
      if($res3->fetch()){
        $status3_price = $res3->get_data(0);
      }

      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date = '". $status->get_value("status_4_date")."' order by trade_date desc limit 1";
      $res4 = $this->get_db()->query($sql);
      $status4_price = 0;
      if($res4->fetch()){
        $status4_price = $res4->get_data(0);
      }
      $uprate = 100;
      if(($status4_price != 0) && ($status3_price != 0)){
        $uprate = round( ($status4_price / $status3_price * 100 -100) ,2);
      }

      $tmp = array();
      $tmp["cliped"] = false;
      $clip = $this->get_clump("clip_clump");
      $clip->set_value("user_id", $user->get_value("id"));
      $clip->set_value("financial_code", $daily->get_value("financial_code"));
      if($clip->get()){
        $tmp["cliped"] = true;
      }
      if($bk == 0){
        continue;
      }

      $tmp["financial_code"] = $daily->get_value("financial_code");
      $tmp["company_name"] = $daily->get_value("company_name");
      $tmp["rate"] = round($daily->get_value("end_price")/$bk*100 - 100, 2);
      $tmp["record_date"] = str_replace("-", "/", $status->get_value("status_3_date"));
      $tmp["uri_date"] = str_replace("-", "/", $status->get_value("status_4_date"));
      $tmp["status3_price"] = $status3_price;
      $tmp["uprate"] = $uprate;
      $tmp["end_price"] = $status4_price;
      $datum[] = $tmp;
    }
*/
    $user = $this->get_user_info();
    $update_date = date("Y-m-d 22:00");
    $datum = array();
    $sql = "select id, column1, column2, column3, column4, column5, column6, column7, column8, column9, created_at from search_focus3";
    $res = $this->get_data_db()->query($sql);
    while($res->fetch()){
      $tmp = array();
      $tmp["financial_code"] = $res->get_data(1);
      $tmp["company_name"] = $res->get_data(2);
      $tmp["rate"] = $res->get_data(3);
      $tmp["record_date"] = $res->get_data(4);
      $tmp["uri_date"] = $res->get_data(5);
      $tmp["status3_price"] = @number_format($res->get_data(6));
      $tmp["uprate"] = $res->get_data(7);
      $tmp["end_price"] = @number_format($res->get_data(8));
      $tmp["status2_price"] = @number_format($res->get_data(9));
      $tmp["cliped"] = util::is_clip($user->get_value("id"), $res->get_data(1));

      $datum[] = $tmp;

      $update_date = $res->get_data(9);
    }
    $smarty->set("datum", $datum);
    
  }

} // end of class


