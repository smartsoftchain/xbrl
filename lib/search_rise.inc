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

class search_rise extends base_model_ambiguous {

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

    $sql = "select max(trade_date) from financial_status where trade_date < '".  $max_date. "'";
    $res = $db->query($sql);
 
    $cal = new calendar;
    $cal->set_now_date();

    $user = $this->get_user_info();

   if($res->fetch()){
      $max_date2 = $res->get_data(0);
    }

    $datum = array();
    $name_list = array();
    $price_list = array();
    $bk_price_list = array();

    $sql = "select end_price, financial_code, company_name from daily_financial_price where trade_date = '". $max_date."'";
    $res = $db->query($sql);
    while($res->fetch()){
      if("" == $res->get_data(1)){ continue; } 
//      if("--unregistered--" == $res->get_data(2)){ continue; }
      if(in_array($res->get_data(1), $this->get_ignore_list())){ continue; }
      $name_list[$res->get_data(1)] = $res->get_data(2);
      $price_list[$res->get_data(1)] = $res->get_data(0);
      $tmp = array();
      $tmp["today"] = $res->get_data(0);
      $datum[$res->get_data(1)] = $tmp;
    }

    $sql = "select financial_code, name from meigara";
    $res = $db->query($sql);
    while($res->fetch()){
      $name_list[$res->get_data(0)] = $res->get_data(1);
    }

    $sql = "select end_price, financial_code, company_name from daily_financial_price where trade_date = '". $max_date2."'";
    $res = $db->query($sql);
    while($res->fetch()){
      if("" == $res->get_data(1)){ continue; } 
//      if("--unregistered--" == $res->get_data(2)){ continue; }
      $bk_price_list[$res->get_data(1)] = $res->get_data(0);
      $datum[$res->get_data(1)]["yesterday"] = $res->get_data(0);
    }

    $tmp = array();
    foreach($datum as $code => $val){
      if((isset($val["today"]) && 0 < $val["today"]) && (isset($val["yesterday"]) && 0 < $val["yesterday"])){
        $tmp[$code] = round($val["today"]/$val["yesterday"]*100, 1);
      }
    }
    arsort($tmp);

    $list = array();
    $i=0;
    foreach($tmp as $code => $rate){
      if($i > 49){ break; }
      if($rate < 100){ break; }

      $dummy = array();
      $dummy["cliped"] = false;
      $clip = $this->get_clump("clip_clump");
      $clip->set_value("user_id", $user->get_value("id"));
      $clip->set_value("financial_code", $code);
      if($clip->get()){
        $dummy["cliped"] = true;
      }

      $dummy["code"] = $code;
      $dummy["name"] = $name_list[$code];
      $dummy["price"] = $price_list[$code];
      $dummy["bk_price"] = $bk_price_list[$code];
      $dummy["rate"] = $rate - 100;
      $list[] = $dummy;
      $i++;
    }
*/
    $user = $this->get_user_info();
    $update_date = date("Y-m-d 22:00");
    $datum = array();
    $sql = "select id, column1, column2, column3, column4, column5, column6, column7, column8, created_at from search_rise";
    $res = $this->get_data_db()->query($sql);
    while($res->fetch()){
      $tmp = array();
      $tmp["code"] = $res->get_data(1);
      $tmp["name"] = $res->get_data(2);
      $tmp["price"] = $res->get_data(3);
      $tmp["bk_price"] = $res->get_data(4);
      $tmp["rate"] = $res->get_data(5);
      $tmp["cliped"] = util::is_clip($user->get_value("id"), $res->get_data(1));

      $datum[] = $tmp;

      $update_date = $res->get_data(9);
    }
 
    $smarty->set("datum", $datum);
    $cal = new calendar;
    $cal->set_string($update_date);
    $smarty->set("date", date("Y年m月d日 H時i分", $cal->get_epoc()));
  }

} // end of class


