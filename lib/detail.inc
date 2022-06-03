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

class detail extends base_model_ambiguous {

  //処理
  public function execute() {
    parent::execute();

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_data_db();

    // 表示させる項目
    $code = $req->find("financial_code");

    $sql = "select financial_code, name from meigara where financial_code = '". $code."'";
    $res = $db->query($sql);
    $name = "";
    while($res->fetch()){
      $name = $res->get_data(1);
    }


    $cal = new calendar;
    $cal->set_now_date();

    $sql = "select max(trade_date) from financial_status";
    $res = $db->query($sql);
    if($res->fetch()){
      $max_date = $res->get_data(0);
    }

    $sql = "select yield_value, end_price, trade_date, company_name from daily_financial_price where financial_code = '". $code. "' and trade_date <= '". $max_date. "' order by trade_date desc limit 21";
    $res = $db->query($sql);

    $datum = array();
 
    $i = 0;

    $status = $this->get_clump("financial_status_clump");

    while($res->fetch()){
      $status->init();
      $status->set_db($db);
      $status->set_value("financial_code", $code);
      $status->set_value("trade_date", $res->get_data(2));
      $status->get_nopk();
      
      if(0 == $i){
        if("" == $name){
          $name = $res->get_data(3);
        }
        $date = $res->get_data(2);
      }

      $tmp = array();
      $tmp["trade_date"] = $res->get_data(2);
      $tmp["end_price"] = $res->get_data(1);
      $tmp["yield_value"] = $res->get_data(0);
      $tmp["20_days_average"] = round($status->get_value("20_days_average"), 1) * 1000;

      $datum[] = $tmp;
      $i++;
    }
    $rev = array_reverse($datum);
    $smarty->set("datum", $rev);
    $cal->set_string($date);

    $smarty->set("code", $code);
    $smarty->set("name", $name);

    $sql = "select max(created_at) from search_focus";
    $res = $db->query($sql);
    $cal = new calendar;
    $cal->set_now_date();
    if($res->fetch()){
      $last_date = $res->get_data(0);
      $cal->set_string($last_date);
    }

    $smarty->set("date", date("Y年m月d日 H時i分", $cal->get_epoc()));
//    $dummy["rate"] = $rate - 100;
  }

} // end of class


