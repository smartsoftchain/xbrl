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

$limit = 3; // 何日前まで？(当日で0)
//XXX TEST

$now = $cal->get_string();

// 本日分のみ洗い出し
//mail("all@infobreak.jp", "start", date("Y-m-d H:i:s"));
for($i=0; $i<=$limit; $i++){
  $val = -1 * $limit + $i;

  $cal->set_string($now);
  $cal->calculation_day($val);
//print $cal->get_string(); exit;

  $db->query("delete from status_change_log where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");
  $db->query("delete from financial_status where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");
  $db->query("delete from daily_financial_price where trade_date >= '". date("Y-m-d", $cal->get_epoc())."'");

  if(true == get_kabu_info($cal, $db, $cobj)){
    analys($cal, $db);
  }
}
mail("all@infobreak.jp", "end", date("Y-m-d H:i:s"));

function get_kabu_info($cal, $db, $cobj){
  $url = $cobj->find("kabu_info_url_base2");
  $url = str_replace("DATE", date("Y-m-d", $cal->get_epoc()), $url);
  
  $csv = @file_get_contents($url);
  $csv = mb_convert_encoding($csv, "UTF-8", "SJIS");
  
  if(false != $csv){
    $datum = explode("\n", $csv);
  
    $clump = new daily_financial_price_clump;

    $i=0;
    foreach($datum as $row){
      $i++;
      if($i==1){ 
        $d = explode(",", trim($row));

        if(date("Y年m月d日", $cal->get_epoc()) != trim($d[0])){
          // 取りたい日じゃない可能性
          return false;
        }
        continue; 
      }
      if($i==2){ continue; }  // 最初の2行は飛ばし
  
      $tmp = explode(",", $row);

      if( ("東証1部" != $tmp[1]) && ("東証2部" != $tmp[1])){
        continue;
      }

  //1301,極洋,東証1部,水産・農林業,269,270,268,268,291000,78207000
      $clump->init();
      $clump->set_db($db);
//      $clump->set_table_name("daily_financial_price2");
      $clump->set_value("trade_date", date("Y-m-d", $cal->get_epoc()));
      $clump->set_value("financial_code", str_replace(array("-T", "-S", "-F"), "", $tmp[0]));
      $clump->set_value("company_name"  , $tmp[2]);
      $clump->set_value("start_price"   , $tmp[4]);
      $clump->set_value("high_price"    , $tmp[5]);
      $clump->set_value("low_price"     , $tmp[6]);
      $clump->set_value("end_price"     , $tmp[7]);
      $clump->set_value("yield_value"   , round($tmp[8]/1000, 4));
      $ret = $clump->insert();
    }
  }
  return true;
}
// end!!
?>
