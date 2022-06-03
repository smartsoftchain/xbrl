<?php
require_once("_base.inc");


class search_focus3 extends base{

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
    $cal = new calendar;
    $cal->set_string($max_date);
    $cal->calculation_year(-1);
    //$from_date = date("Y-m-d", $cal->get_epoc());
    $from_date = date("Y-m-d", strtotime("-90 day"));
    //$from_date = date("2016-01-01");

    //$sql = "select financial_code, trade_date from status_change_log where after_status = 4 and trade_date >= '". $from_date. "' and trade_date <= '". $max_date."' order by financial_code asc";
    $sql = "select financial_code, trade_date from status_change_log where after_status = 3 and trade_date >= '". $from_date. "' and trade_date <= '". $max_date."' order by financial_code asc";
    //$sql = "select financial_code, trade_date from status_change_log where after_status = 3 and trade_date <= '". $max_date."' order by financial_code asc";

    $res = $db->query($sql);
    echo $sql."\n";

    $cal->set_now_date();

    $datum = array();
    while($res->fetch()){
      $financial_code = $res->get_data(0);
      $trade_date = $res->get_data(1);

      $status = $this->get_clump("financial_status_clump");
      $status->set_value("financial_code", $financial_code);
      $status->set_value("trade_date", $trade_date);
      $status->get_nopk();
      if("" == $status->get_value("id")){
        continue;
      }

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
      //echo $sql."\n";
      $res3 = $this->get_db()->query($sql);
      $status3_price = 0;
      if($res3->fetch()){
        $status3_price = $res3->get_data(0);
      }
      
      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date = '". $status->get_value("status_2_date")."' order by trade_date desc limit 1";
      //echo $sql."\n";
      $res3 = $this->get_db()->query($sql);
      $status2_price = 0;
      if($res3->fetch()){
        $status2_price = $res3->get_data(0);
      }
      

      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date = '". $status->get_value("status_4_date")."' order by trade_date desc limit 1";
       //echo $sql."\n";
      $res4 = $this->get_db()->query($sql);
      $status4_price = 0;
      if($res4->fetch()){
        $status4_price = $res4->get_data(0);
      }
      $uprate = 100;
      if(($status3_price != 0) && ($status2_price != 0)){
        $uprate = round( ($status3_price / $status2_price * 100 -100) ,2);
      }
echo $status->get_value("financial_code")."=>".$status3_price."\n";
      $tmp = array();
      if($bk == 0){
        continue;
      }

      $tmp["financial_code"] = $daily->get_value("financial_code");
      $tmp["company_name"] = $daily->get_value("company_name");
      $tmp["rate"] = round($daily->get_value("end_price")/$bk*100 - 100, 2);
      //$tmp["record_date"] = str_replace("-", "/", $status->get_value("status_3_date"));
      $tmp["record_date"] = str_replace("-", "/", $status->get_value("status_2_date"));
      $tmp["uri_date"] = str_replace("-", "/", $status->get_value("status_3_date"));
      $tmp["status3_price"] = $status3_price;
      $tmp["uprate"] = $uprate;
      $tmp["end_price"] = $status4_price;
      $tmp["status2_price"] = $status2_price;
      $datum[] = $tmp;
    }
    foreach($datum as $data){
      $clump = $this->get_clump("search_focus3_clump");

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


$obj = new search_focus3;
$obj->set_db($dbh);
$obj->execute();
$obj->change_version();
?>
