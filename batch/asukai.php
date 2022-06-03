<?php
require_once("_base.inc");


class asukai extends base{

  public function __construct(){
    parent::__construct();
    $this->set_table_name(get_class($this));
  }

  public function execute(){
    $db = $this->get_db();

    $sql = "select max(trade_date) from financial_status";
    $res = $db->query($sql);
    if($res->fetch()){
      $max_date = $res->get_data(0);
    }

    $sql = "select id from financial_status where status = 2 and status_2_date = '". $max_date."' order by financial_code asc";
//    $sql = "select id from financial_status where status = 3 and status_3_date = '". $max_date."' order by financial_code asc";
    $res = $db->query($sql);
    
    $cal = new calendar;
    $cal->set_now_date();

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

      if(in_array($status->get_value("financial_code"), $this->get_ignore_list())){ continue; }

      if("--unregistered--" == $daily->get_value("company_name")){
//        continue;
      }
      if($daily->get_value("end_price") == 0){
        continue;
      }

      $result = -4;

      $tmp = array();
      $tenki = 1;
      $sql = "select judge from comparison_financial_data where financial_code = '". $daily->get_value("financial_code")."' order by end_date desc, id desc limit 1";
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
      $tmp["rank"] = -1 * $result;
      $tmp["tenki"] = $tenki;
      $datum[] = $tmp;
    }
    foreach($datum as $data){
      $clump = $this->get_clump("asukai_clump");

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
$obj = new asukai;
$obj->set_db($dbh);
$obj->execute();
$obj->change_version();
?>
