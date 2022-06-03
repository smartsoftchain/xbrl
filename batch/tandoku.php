<?php
require_once("batch_base.php");
require_once("clump/daily_financial_price_clump.inc");
require_once("common/analys_finance.inc");

$db = $dbh;

/*
	$sql = "select * from financial_status where `status`=2 order by `financial_code`";
  	$res = $dbh->query($sql);
  	while($res->fetch()){  
		$codes = $res->get_data(3);
		$status_0_date = $res->get_data(9);
		$status_1_date = $res->get_data(10);
		$status_2_date = $res->get_data(11);
		$status_3_date = $res->get_data(12);
		$status_4_date = $res->get_data(13);
		
	    $sql = "select yield_value from daily_financial_price where financial_code = '". $codes."' and trade_date = '". $status_1_date."'";
	    $res2 = $dbh->query($sql);
	    $status1_yield = 0;
	    if($res2->fetch()){
	      $status1_yield = $res2->get_data(9);
	    }

	    if($target->get_value("yield_value") > ($status1_yield * 7)){
	      $this->write_change_log($status->get_value("status"), 3);
	      $status->set_value("status", 3);
	      $status->set_value("status_3_date", date("Y-m-d", $this->get_cal()->get_epoc()));
	      $status->set();
	      $this->set_status($status);
	    }
	}


exit;
*/


	//管理画面からテスト用に単独でまわす場合
	$from = (isset($_REQUEST['from'])) ? $_REQUEST['from'] : date("Y-m-d");
	$to = (isset($_REQUEST['to'])) ? $_REQUEST['to'] : date("Y-m-d");
	
	//テスト用
	$from = "2016-01-01";
	$to = "2016-06-30";
	
$ttday = 0;

function day_diff($date1, $date2) {
 
    $timestamp1 = strtotime($date1);
    $timestamp2 = strtotime($date2);
    $seconddiff = abs($timestamp2 - $timestamp1);
    $daydiff = $seconddiff / (60 * 60 * 24);
    return $daydiff;
 
}
$limit1 = day_diff('2016-01-01', date("Y-m-d"));

$limit2 = day_diff('2016-04-30', date("Y-m-d"));
$limit2 = 0;


$cal = new calendar;
$cal->set_now_date();
$now = $cal->get_string();

// 本日分のみ洗い出し
//for($i=0; $i<=$limit; $i++){
  //$val = -1 * $limit + $i;
for($i=$limit2; $i<=$limit1; $i++){
  $val = -1 * $i;
  $cal->set_string($now);
  $cal->calculation_day($val);

echo "start-".date("Y-m-d", $cal->get_epoc())."\n";

//print $cal->get_string(). "\n";
//exit;

		if($cal->get_epoc()){
				$db->query("delete from status_change_log where trade_date = '". date("Y-m-d", $cal->get_epoc())."'");
				$db->query("delete from financial_status where trade_date = '". date("Y-m-d", $cal->get_epoc())."'");
				$db->query("delete from financial_status2 where trade_date = '". date("Y-m-d", $cal->get_epoc())."'");
				//$db->query("delete from daily_financial_price where trade_date >= '". $trade_date."'");
				//$db->query("delete from daily_financial_price2 where trade_date >= '". $trade_date."'");
				
				analys($cal, $db);
		}

}

echo "end-".date("Y-m-d H:i:s")."\n";

		exec("/usr/bin/php /var/www/html/xbrl/batch/asukai.php");
		exec("/usr/bin/php /var/www/html/xbrl/batch/asuuri.php");
		exec("/usr/bin/php /var/www/html/xbrl/batch/search_focus.php");
		exec("/usr/bin/php /var/www/html/xbrl/batch/search_focus2.php");
		exec("/usr/bin/php /var/www/html/xbrl/batch/search_focus3.php");
		exec("/usr/bin/php /var/www/html/xbrl/batch/search_rise.php");
	

	

function analys($cal, $dbh){
	$trade_date = date("Y-m-d", $cal->get_epoc());

  
  // 対象となるデータピックアップ
  $sql = "select financial_code from daily_financial_price where trade_date = '". $trade_date."'";
  $res = $dbh->query($sql);
  $codes = array();
  while($res->fetch()){  
    if($res->get_data(0) == ""){ continue; }
    $codes[] = $res->get_data(0);
  }

  $day_price = new daily_financial_price_clump;
  
  $analys = new analys_finance;
  $analys->set_db($dbh);
  
  foreach($codes as $financial_code){
    $analys->init();

print $trade_date. "__". $financial_code."\n";
file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_analyslog.txt', "trade_date=>".$trade_date." financial_code=>".$financial_code." ".date("Y/m/d H:i:s")."\n", FILE_APPEND);

    $day_price->init();
    $day_price->set_db($dbh);  
    $day_price->set_value("trade_date", $trade_date);
    $day_price->set_value("financial_code", $financial_code);
    if(false == $day_price->get()){
      continue;
    }
    $analys->set_target($day_price);
    $analys->set_cal($cal);
  
    // 対象銘柄を順番に分析にかける
    // 共通分析を行う
    $analys->common_analys();

    // フェーズごとに次のフェーズに映ったかどうかをチェック
    $analys->phase_analys();
  }
  
}
?>