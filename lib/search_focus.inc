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

class search_focus extends base_model_ambiguous {

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

    $sql = "select id from financial_status where (status = 1 and trade_date = '". $max_date."') or (status = 2 and status_2_date = '". $max_date."') order by financial_code asc";

    $sql = "select id from financial_status where status = 1 and trade_date = '". $max_date. "' order by financial_code asc";
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
      $avg = $status->get_value("20_days_average");
if($avg==0){
  continue;
}

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

      if($status->get_value("status") == "1"){ 
        $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date >= '". $status->get_value("status_1_date")."' and trade_date <= '". date("Y-m-d", $cal->get_epoc())."' order by trade_date desc limit 6";
    
        $res2 = $this->get_db()->query($sql);
       
        $result = 0;
        $tmp = array();
        $i = 0;
        while($res2->fetch()){
          $end = $res2->get_data(0);
          $tmp[] = $end;
          if($i != 0){
            if($bk > $end){
              $result--;
            }else{
              $result = 0;
            }
          }
          $bk = $end;
          $i++;
        }
        $tmp = array_reverse($tmp);
        foreach($tmp as $i => $end){
          if($i != 0){
            if($bk > $end){
              $result--;
            }else{
              $result = 0;
            }
          }
          $bk = $end;
        }
      }

      $tmp = array();
      $tmp["cliped"] = false;
      $clip = $this->get_clump("clip_clump");
      $clip->set_value("user_id", $user->get_value("id"));
      $clip->set_value("financial_code", $daily->get_value("financial_code"));
      if($clip->get()){
        $tmp["cliped"] = true;
      }

      $dekidaka_rate = util::calc_oodekidaka_rate($status);
      $tmp["dekidaka_rate"] = $dekidaka_rate;
      $tmp["financial_code"] = $daily->get_value("financial_code");
      $tmp["company_name"] = $daily->get_value("company_name");
      $tmp["end_price"] = $daily->get_value("end_price");
      $tmp["rate"] = round($daily->get_value("yield_value") / $avg, 1);
      $tmp["record_date"] = str_replace("-", "/", $status->get_value("status_1_date"));
      $tmp["rank"] = -1 * $result;
      $datum[] = $tmp;
    }
    $smarty->set("more_datum", $datum);
*/
    $user = $this->get_user_info();
    $update_date = date("Y-m-d 22:00");
    $datum = array();
    $sql = "select id, column1, column2, column3, column4, column5, column6, column7, column8, created_at from search_focus";
    $res = $this->get_data_db()->query($sql);
    while($res->fetch()){
      $tmp = array();
      $tmp["dekidaka_rate"] = $res->get_data(1);
      $tmp["financial_code"] = $res->get_data(2);
      $tmp["company_name"] = $res->get_data(3);
      $tmp["end_price"] = $res->get_data(4);
      $tmp["rate"] = $res->get_data(5);
      $tmp["record_date"] = $res->get_data(6);
      $tmp["rank"] = $res->get_data(7);
      $tmp["cliped"] = util::is_clip($user->get_value("id"), $res->get_data(2));

      $datum[] = $tmp;

      $update_date = $res->get_data(9);
    }
 

    $smarty->set("more_datum", $datum);

    $cal = new calendar;
    $cal->set_string($update_date);
    $smarty->set("date", date("Y年m月d日 H時i分", $cal->get_epoc()));
    $smarty->set("date2", date("Y年m月d日", $cal->get_epoc()));

  }

} // end of class


