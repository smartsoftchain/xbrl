<?php
/**********************************************************
 * 
 **********************************************************/
set_time_limit(0);

require_once("batch_base.php");
require_once("clump/daily_financial_price_clump.inc");
require_once("clump/clip_clump.inc");
require_once("clump/user_clump.inc");
require_once("clump/mail_template_clump.inc");
require_once("common/analys_finance.inc");

$cal = new calendar;
$cal->set_now_date();
send($cal, $dbh);


function send($cal, $db){
  $sql = "select max(trade_date) from daily_financial_price";
  $res = $db->query($sql);
  if($res->fetch()){
    $trade_date = $res->get_data(0);
  }else{
    return;
  }

  $cal_t = new calendar;
  $cal_t->set_now_date();
  $cal_t->calculation_day(-1);
  if($trade_date != date("Y-m-d", $cal_t->get_epoc())){
    return;
  }

  // 本日の買い銘柄あるか
  $sql = "select id from financial_status where status = 2 and status_2_date = '". $trade_date."' order by financial_code asc";
  $res = $db->query($sql);

  $buy_datum = array();
  while($res->fetch()){
    $financial_id = $res->get_data(0);
    $status = new financial_status_clump;
    $status->set_db($db);
    $status->set_value("id", $financial_id);
    $status->get();

    $daily = new daily_financial_price_clump;
    $daily->set_db($db);
    $daily->set_value("trade_date", $status->get_value("trade_date"));
    $daily->set_value("financial_code", $status->get_value("financial_code"));
    $daily->get();

    $name = $daily->get_value("company_name");
    $code = $status->get_value("financial_code");

    $buy_datum[$code] = $name;
  }

  // 本日の売り銘柄あるか
  $sql = "select id from financial_status where status = 4 and status_4_date = '". $trade_date."' order by financial_code asc";
  $res = $db->query($sql);
    
  $sell_datum = array();
  while($res->fetch()){
    $financial_id = $res->get_data(0);
    $status = new financial_status_clump;
    $status->set_db($db);
    $status->set_value("id", $financial_id);
    $status->get();

    $daily = new daily_financial_price_clump;
    $daily->set_db($db);
    $daily->set_value("trade_date", $status->get_value("trade_date"));
    $daily->set_value("financial_code", $status->get_value("financial_code"));
    $daily->get();

    $name = $daily->get_value("company_name");
    $code = $status->get_value("financial_code");

    $sell_datum[$code] = $name;
  }

  if(!empty($buy_datum)){
    buy_send($buy_datum, $db);
  }

  if(!empty($sell_datum)){
    sell_send($sell_datum, $db);
  }
}

function buy_send($datum, $db){
  $mt = new mail_template_clump;
  $mt->set_db($db);
  $mt->set_value("id", 1);
  if(false == $mt->get()){
    return;
  }
  $datum_string = "";
  foreach($datum as $code => $name){
    $datum_string .= $code. " ". $name."\n";
  }

  $mailfrom="From:" .mb_encode_mimeheader($mt->get_value("from_name")) ."<". $mt->get_value("from_address"). ">";
  $body = $mt->get_value("body");
  $body = mb_ereg_replace("%%%datum%%%", $datum_string, $body);

  $user_list = get_user_list($db);

  foreach($user_list as $user){
    $body_t = mb_ereg_replace("%%%name%%%", $user["name"], $body);
    $ret = mb_send_mail($user["mail"], $mt->get_value("subject"), $body_t, $mailfrom);
  }
}

function sell_send($datum, $db){
  $mt = new mail_template_clump;
  $mt->set_db($db);
  $mt->set_value("id", 2);
  if(false == $mt->get()){
    return;
  }
  $datum_string = "";
  foreach($datum as $code => $name){
    $datum_string .= $code. " ". $name."\n";
  }

  $mailfrom="From:" .mb_encode_mimeheader($mt->get_value("from_name")) ."<". $mt->get_value("from_address"). ">";
  $body = $mt->get_value("body");
  $body = mb_ereg_replace("%%%datum%%%", $datum_string, $body);

  $user_list = get_user_list($db);

  foreach($user_list as $user){
    $body_t = mb_ereg_replace("%%%name%%%", $user["name"], $body);
    mb_send_mail($user["mail"], $mt->get_value("subject"), $body_t, $mailfrom);
  }
}

function get_user_list($db){
  $sql = "select name, mail from user where status = 0 ";
//XXX TEST
//  $sql .= "and id = 1";
  
  $res = $db->query($sql);

  $data = array();
  while($res->fetch()){
    $tmp = array();
    $tmp["name"] = $res->get_data(0);
    $tmp["mail"] = $res->get_data(1);
    $data[] = $tmp;
  }
  return $data;
}

// end!!
?>
