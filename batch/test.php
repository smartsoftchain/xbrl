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
require_once("clump/financial_status_clump.inc");
require_once("calendar.inc");

$cal = new calendar;
$cal->set_now_date();

$status = new financial_status_clump;
$status->set_db($dbh);
$status->set_value("id", 452156);
$status->get();
//XXX
//$status->set_value("status_1_date", "2014-04-28");


$target = new daily_financial_price_clump;
$target->set_db($dbh);
$target->set_value("trade_date", "2014-04-28");
$target->set_value("financial_code", "7985");
$target->get();

$a = new analys_finance;
$a->set_db($dbh);
$a->set_status($status);
$a->set_target($target);
$cal = new calendar;
$cal->set_string("2014-04-28");
$a->set_cal($cal);

$a->check_1($status);



// end!!
?>
