<?php
require_once("_base.inc");


class search_rise extends base{

  public function __construct(){
    parent::__construct();
    $this->set_table_name(get_class($this));
  }

  public function execute(){
    $db = $this->get_db();

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

      $dummy["code"] = $code;
      $dummy["name"] = $name_list[$code];
      $dummy["price"] = $price_list[$code];
      $dummy["bk_price"] = $bk_price_list[$code];
      $dummy["rate"] = $rate - 100;
      $list[] = $dummy;
      $i++;
    }
    foreach($list as $data){
      $clump = $this->get_clump("search_rise_clump");

      $i = 1;
      foreach($data as $val){
        $clump->set_value("column". $i, $val);
        $i++;
      }
      $clump->set_value_nowdate("created_at");
      $clump->insert();
    }

  }
}

$obj = new search_rise;
$obj->set_db($dbh);
$obj->execute();
$obj->change_version();
?>
