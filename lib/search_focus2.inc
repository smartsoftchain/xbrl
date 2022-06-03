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

class search_focus2 extends base_model_ambiguous {

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

//    $sql = "select id from financial_status where (status = 1 and trade_date = '". $max_date."') or (status = 2 and status_2_date = '". $max_date."') order by financial_code asc";

    $sql = "select id from financial_status where status = 3 and trade_date = '". $max_date. "' order by financial_code asc";
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
      $avg = $status->get_value("20_days_average");

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

      $tmp = array();
      $tmp["cliped"] = false;
      $clip = $this->get_clump("clip_clump");
      $clip->set_value("user_id", $user->get_value("id"));
      $clip->set_value("financial_code", $daily->get_value("financial_code"));
      if($clip->get()){
        $tmp["cliped"] = true;
      }

      $tenki = 1;
      $code = $daily->get_value("financial_code");
      $sql = "select judge from comparison_financial_data where financial_code = '". $code."' order by end_date desc, id desc limit 1";
      $res2 = $db->query($sql);
      if($res2->fetch()){
        $tenki = $res2->get_data(0);
      }


      $dekidaka_rate = util::calc_oodekidaka_rate($status);
      $tmp["dekidaka_rate"] = $dekidaka_rate;
      $tmp["financial_code"] = $daily->get_value("financial_code");
      $tmp["company_name"] = $daily->get_value("company_name");
      $tmp["end_price"] = $daily->get_value("end_price");
      $tmp["rate"] = round($daily->get_value("yield_value") / $avg, 1);
      $tmp["rankup_date"] = str_replace("-", "/", $status->get_value("status_1_date"));
      $tmp["record_date"] = str_replace("-", "/", $status->get_value("status_3_date"));
      $tmp["tenki"] = $tenki;
      $datum[] = $tmp;
    }
    $smarty->set("more_datum", $datum);
//---------------------
    $sql = "select id from financial_status where status = 3 and trade_date = '". $max_date. "' order by financial_code asc";
    $res = $db->query($sql);
    
    $cal = new calendar;
    $cal->set_now_date();

    $datum = array();
    while($res->fetch()){
      $financial_id = $res->get_data(0);
      $status = $this->get_clump("financial_status_clump");
      $status->set_value("id", $financial_id);
      $status->get();

      if(in_array($status->get_value("financial_code"), $this->get_ignore_list())){ continue; }
      $avg = $status->get_value("20_days_average");

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
       
      $end = $daily->get_value("end_price");
      while($res2->fetch()){
        $end = $res2->get_data(0);
      }
      if(0 == $end){
        continue;
      }

      $tenki = 1;
      $code = $daily->get_value("financial_code");
      $sql = "select judge from comparison_financial_data where financial_code = '". $code."' order by end_date desc, id desc limit 1";
      $res2 = $db->query($sql);
      if($res2->fetch()){
        $tenki = $res2->get_data(0);
      }

      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date = '". $status->get_value("status_3_date")."' order by trade_date desc limit 1";
      $res3 = $this->get_db()->query($sql);
      $status3_price = 0;
      if($res3->fetch()){
        $status3_price = $res3->get_data(0);
      }

      $tmp = array();
      $tmp["cliped"] = false;
      $dekidaka_rate = util::calc_oodekidaka_rate($status);
      $tmp["dekidaka_rate"] = $dekidaka_rate;
      $clip = $this->get_clump("clip_clump");
      $clip->set_value("user_id", $user->get_value("id"));
      $clip->set_value("financial_code", $daily->get_value("financial_code"));
      if($clip->get()){
        $tmp["cliped"] = true;
      }

      $tmp["financial_code"] = $daily->get_value("financial_code");
      $tmp["company_name"] = $daily->get_value("company_name");
      $tmp["end_price"] = $daily->get_value("end_price");
      $tmp["rate"] = round($daily->get_value("end_price") / $status3_price * 100 - 100, 1);
      $tmp["rankup_date"] = str_replace("-", "/", $status->get_value("status_1_date"));
      $tmp["record_date"] = str_replace("-", "/", $status->get_value("status_3_date"));
      $tmp["tenki"] = $tenki;
      $tmp["status3_price"] = $status3_price;

      $datum[] = $tmp;
    }
*/
    $user = $this->get_user_info();
    $update_date = date("Y-m-d 22:00");
    $datum = array();
    $sql = "select column1, column2, column3, column4, column5, column6, column7, column8, column9, created_at from search_focus2";
    $res = $this->get_data_db()->query($sql);
    while($res->fetch()){
      $tmp = array();
      $tmp["dekidaka_rate"] = $res->get_data(0);
      $tmp["financial_code"] = $res->get_data(1);
      $tmp["company_name"] = $res->get_data(2);
      $tmp["end_price"] = $res->get_data(3);
      $tmp["rate"] = $res->get_data(4);
      $tmp["rankup_date"] = $res->get_data(5);
      $tmp["record_date"] = $res->get_data(6);
      $tmp["tenki"] = $res->get_data(7);
      $tmp["status3_price"] = $res->get_data(8);
      $tmp["cliped"] = util::is_clip($user->get_value("id"), $res->get_data(1));

      $datum[] = $tmp;

      $update_date = $res->get_data(9);
    }
    $smarty->set("most_datum", $datum);

    $cal = new calendar;
    $cal->set_string($update_date);
    $smarty->set("date", date("Y年m月d日 H時i分", $cal->get_epoc()));
    $smarty->set("date2", date("Y年m月d日", $cal->get_epoc()));
  }

} // end of class


