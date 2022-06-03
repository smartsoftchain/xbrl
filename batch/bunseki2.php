<?php
/**********************************************************
 * 
 **********************************************************/
set_time_limit(0);

require_once("batch_base.php");
require_once("clump/daily_financial_price_clump.inc");
require_once("common/analys_finance2.inc");

function analys($cal, $dbh){
  $trade_date = date("Y-m-d", $cal->get_epoc());
  
  // 対象となるデータピックアップ
  $sql = "select financial_code from daily_financial_price2 where trade_date = '". $trade_date."' and financial_code != ''";
  $res = $dbh->query($sql);
  $codes = array();
  while($res->fetch()){  
    $codes[] = $res->get_data(0);
  }
  $day_price = new daily_financial_price_clump;
  
  $analys = new analys_finance;
  $analys->set_db($dbh);
  
  foreach($codes as $financial_code){
    $analys->init();

    $day_price->init();
    $day_price->set_table_name("daily_financial_price2");
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
print "batch end!!\n";

// end!!
?>
