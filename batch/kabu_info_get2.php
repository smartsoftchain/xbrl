<?php
/**********************************************************
 * 
 **********************************************************/
require_once("batch_base.php");
require_once("clump/daily_financial_price_clump.inc");
//require_once("bunseki2.php");
require_once("bunseki.php");

$db = $dbh;

$cal = new calendar;
$cal->set_now_date();

$limit = 0; // 何日前まで？(当日で0)
//XXX TEST
$now = $cal->get_string();

// 本日分のみ洗い出し

for($i=0; $i<=$limit; $i++){
  $val = -1 * $limit + $i;

  $cal->set_string($now);
  $cal->calculation_day($val);

//print $cal->get_string(). "\n";
//exit;
echo date("Y-m-d", $cal->get_epoc())."\n";
  $db->query("delete from status_change_log where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");
  $db->query("delete from financial_status where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");
  $db->query("delete from financial_status2 where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");
  $db->query("delete from daily_financial_price where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");
  $db->query("delete from daily_financial_price2 where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");
  if(true == get_kabu_info($cal, $db, $cobj)){

    analys($cal, $db);
  }
}

function get_kabu_info($cal, $db, $cobj){
  $url = $cobj->find("kabu_info_url_base2");
  $url = str_replace("DATE", date("Y-m-d", $cal->get_epoc()), $url);
  //$url = "http://k-db.com/stocks/2016-07-01?download=csv";
echo $url."\n";
  $csv = @file_get_contents($url);
  if(!$csv){
    mail("all@infobreak.jp; post@fun-system.info", "[DEV]error", "[DEV]CSV file couldn't import to server.\n".$url, "From: infobreak@infobreak.dev");
    exit;
  }
  
  $csv = mb_convert_encoding($csv, "UTF-8", "SJIS");
  
  if(false != $csv){
    $datum = explode("\n", $csv);
  
    $clump = new daily_financial_price_clump;

    $i=0;
    foreach($datum as $row){
      $i++;
      if($i==1){ 
        $d = explode(",", trim($row));
        /*
        if(date("Y年m月d日", $cal->get_epoc()) != trim($d[0])){
          // 取りたい日じゃない可能性
          return false;
        }
        */
        continue; 
      }
     // if($i==1){ continue; }  // 最初の1行は飛ばし
  
      $tmp = explode(",", $row);
      if(!isset($tmp[1])){
        continue;
      }
      if(("東証1部" != $tmp[2]) && ("東証2部" != $tmp[2])){
        continue;
      }

  //1301,極洋,東証1部,水産・農林業,269,270,268,268,291000,78207000
/*      $clump->init();
      $clump->set_db($db);
      $clump->set_value("trade_date", date("Y-m-d", $cal->get_epoc()));
      $clump->set_value("financial_code", str_replace(array("-T", "-S", "-F"), "", $tmp[0]));
      $clump->set_value("company_name"  , $tmp[2]);
      $clump->set_value("start_price"   , $tmp[4]);
      $clump->set_value("high_price"    , $tmp[5]);
      $clump->set_value("low_price"     , $tmp[6]);
      $clump->set_value("end_price"     , $tmp[7]);
      $clump->set_value("yield_value"   , round($tmp[8]/1000, 4));
*/

      $clump->init();
      $clump->set_db($db);
      $clump->set_value("trade_date", date("Y-m-d", $cal->get_epoc()));
      $clump->set_value("financial_code", str_replace(array("-T", "-S", "-F"), "", $tmp[0]));
      $clump->set_value("company_name"  , $tmp[1]);
      $clump->set_value("start_price"   , $tmp[3]);
      $clump->set_value("high_price"    , $tmp[4]);
      $clump->set_value("low_price"     , $tmp[5]);
      $clump->set_value("end_price"     , $tmp[6]);
      $clump->set_value("yield_value"   , round($tmp[7]/1000, 4));
      $ret = $clump->insert();
    }
  }
  return true;
}
// end!!
?>
