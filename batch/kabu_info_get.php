<?php
/**********************************************************
 * 
 **********************************************************/
require_once("batch_base.php");
require_once("clump/daily_financial_price_clump.inc");

$db = $dbh;

$cal = new calendar;
$cal->set_now_date();

get_kabu_info($cal, $cobj, $db);

function get_kabu_info($cal, $cobj, $db){

  $tsv = @file_get_contents($cobj->find("kabu_info_url_base")."s". date("Ymd", $cal->get_epoc()). ".txt");
  $tsv = mb_convert_encoding($tsv, "UTF-8", "SJIS");
  
  if(false != $tsv){
    $datum = explode("\n", $tsv);
  
    $clump = new daily_financial_price_clump;
    $i=0;
    foreach($datum as $row){
      $i++;
      if($i==1){ continue; }  // 最初の1行は飛ばし
  
      $tmp = explode("\t", $row);
      if("--unregistered--" == $row["1"]){
        continue;
      }
  
      $clump->init();
      $clump->set_db($db);
      $clump->set_value("trade_date", date("Y-m-d", $cal->get_epoc()));
      $clump->set_value("financial_code", $tmp[0]);
      $clump->set_value("company_name", $tmp[1]);
      $clump->set_value("start_price", $tmp[2]);
      $clump->set_value("end_price", $tmp[5]);
      $clump->set_value("high_price", $tmp[3]);
      $clump->set_value("low_price", $tmp[4]);
      $clump->set_value("yield_value", $tmp[6]);
      $clump->insert();
    }
  }
}
print "batch end!!\n";

// end!!
?>
