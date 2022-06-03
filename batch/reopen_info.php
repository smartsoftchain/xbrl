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
reopen($cal, $dbh);


function reopen($cal, $db){
  $date = date("Y-m-d", $cal->get_epoc());
  $sql = "delete from ignore_list where reopen_at = '". $date."'";
  $db->query($sql);
}
// end!!
?>
