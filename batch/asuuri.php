<?php
require_once("_base.inc");


class asuuri extends base{

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

    //$sql = "select id from financial_status where status = 4 and status_4_date = '". $max_date."' order by financial_code asc";
    $sql = "select id from financial_status where status >= 3 and status_4_date = '". $max_date."' order by financial_code asc";
    echo $sql."\n";
    $res = $db->query($sql);
    
    $cal = new calendar;
    $cal->set_now_date();

    $datum = array();
    while($res->fetch()){
      $financial_id = $res->get_data(0);
      $status = $this->get_clump("financial_status_clump");
      $status->set_value("id", $financial_id);
      $status->get();

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
      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date = '". $status->get_value("status_2_date")."' order by trade_date desc limit 1";
      $res22 = $this->get_db()->query($sql);
      $status2_price = 0;
      if($res22->fetch()){
        $status2_price = $res22->get_data(0);
      }

      $sql = "select end_price from daily_financial_price where financial_code = '". $status->get_value("financial_code")."' and trade_date = '". $status->get_value("status_4_date")."' order by trade_date desc limit 1";
      $res4 = $this->get_db()->query($sql);
      $status4_price = 0;
      if($res4->fetch()){
        $status4_price = $res4->get_data(0);
      }
      $uprate = 100;
      if(($status4_price != 0) && ($status3_price != 0)){
        $uprate = round( ($status3_price / $status2_price * 100 -100) ,2);
      }

      $tmp = array();

      $tmp["financial_code"] = $daily->get_value("financial_code");
      $tmp["company_name"] = $daily->get_value("company_name");
      $tmp["end_price"] = $daily->get_value("end_price");
      $tmp["rate"] = round($daily->get_value("end_price")/$bk*100 - 100, 2);
      //$tmp["record_date"] = str_replace("-", "/", $status->get_value("status_3_date"));
      $tmp["record_date"] = str_replace("-", "/", $status->get_value("status_2_date"));
      //$tmp["status3_price"] = $status3_price;
      $tmp["status2_price"] = $status2_price;
      $tmp["status_3_date"] = str_replace("-", "/", $status->get_value("status_3_date"));
      $tmp["uprate"] = $uprate;
      $tmp["status2_price"] = $status2_price;
      $datum[] = $tmp;
    }
    foreach($datum as $data){
      $clump = $this->get_clump("asuuri_clump");

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


$obj = new asuuri;
$obj->set_db($dbh);
$obj->execute();
$obj->change_version();
?>
