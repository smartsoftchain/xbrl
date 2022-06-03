<?php
require_once("_base.inc");


class search_focus extends base{

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

    $sql = "select id from financial_status where status = 1 and trade_date = '". $max_date. "' order by financial_code asc";
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

      $tmp = array();

      $dekidaka_rate = util::calc_oodekidaka_rate($status);
      $tmp["dekidaka_rate"] = $dekidaka_rate;
      $tmp["financial_code"] = $daily->get_value("financial_code");
      $tmp["company_name"] = $daily->get_value("company_name");
      $tmp["end_price"] = $daily->get_value("end_price");
      $tmp["rate"] = round($daily->get_value("yield_value") / $avg, 1);
      $tmp["record_date"] = str_replace("-", "/", $status->get_value("status_1_date"));
      $tmp["rank"] = $status->get_value("rank");
      $datum[] = $tmp;
    }
    foreach($datum as $data){
      $clump = $this->get_clump("search_focus_clump");

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


$obj = new search_focus;
$obj->set_db($dbh);
$obj->execute();
$obj->change_version();
?>
