<?php
require_once("batch_base.php");
require_once("clump/daily_financial_price_clump.inc");
require_once("common/analys_finance3.inc");

$db = $dbh;
$ttday = 0;

$argv = $_SERVER["argv"];
if($argv){
	$db->query("TRUNCATE TABLE setting");
	$db->query("INSERT INTO `setting`(`col1`, `col2`, `col3`, `col4`) VALUES ('".$argv[1]."','".$argv[2]."','".$argv[3]."','".$argv[4]."')");
	$email = $argv[5];
}



function day_diff($date1, $date2) {
 
    $timestamp1 = strtotime($date1);
    $timestamp2 = strtotime($date2);
    $seconddiff = abs($timestamp2 - $timestamp1);
    $daydiff = $seconddiff / (60 * 60 * 24);
    return $daydiff;
 
}
$limit = day_diff('2016-05-01', date("Y-m-d"));

$cal = new calendar;
$cal->set_now_date();
$now = $cal->get_string();

// 本日分のみ洗い出し
for($i=0; $i<=$limit; $i++){
  $val = -1 * $limit + $i;
  $cal->set_string($now);
  $cal->calculation_day($val);

echo "start-".date("Y-m-d", $cal->get_epoc())."\n";

		if($cal->get_epoc()){
				//$db->query("delete from status_change_log where trade_date = '". date("Y-m-d", $cal->get_epoc())."'");
				//$db->query("delete from financial_status where trade_date = '". date("Y-m-d", $cal->get_epoc())."'");
				//$db->query("delete from financial_status2 where trade_date = '". date("Y-m-d", $cal->get_epoc())."'");
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
	
file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_end.txt', "".date("Y/m/d H:i:s").'=>'.$email."\n");
if($email){
mail($email, "setting_end", "setting-end", "From: info@sfntoushi.com");
}

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
file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_analyslog3.txt', "trade_date=>".$trade_date." financial_code=>".$financial_code." ".date("Y/m/d H:i:s")."\n", FILE_APPEND);

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
    //$analys->common_analys();

    // フェーズごとに次のフェーズに映ったかどうかをチェック
    $analys->phase_analys();
  }
  
}
?>