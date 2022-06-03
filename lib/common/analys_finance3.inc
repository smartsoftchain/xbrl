<?php
require_once("clump/financial_status_clump.inc");
require_once("clump/status_change_log_clump.inc");

class analys_finance {
  private $db_;
  private $target_;
  private $ca_;
  private $status_obj_;

  public function __construct(){
    $this->db_ = null;
    $this->init();
  }
  public function init(){
    $this->target_ = null;
    $this->cal_ = null;
    $this->status_obj_ = null;
  }

  public function set_target($o){ $this->target_ = $o; }
  public function get_target(){ return $this->target_; }
  public function set_db($o){ $this->db_ = $o; }
  public function get_db(){ return $this->db_; }
  public function set_cal($o){ $this->cal_ = $o; }
  public function get_cal(){ return $this->cal_; }
  public function set_status($o){ $this->status_obj_ = $o; }
  public function get_status(){ return $this->status_obj_; }

  public function common_analys(){
    // 共通での処理
    $target = $this->get_target();

    $sql = "select id from financial_status where trade_date = '". date("Y-m-d", $this->get_cal()->get_epoc()). "' and financial_code = '". $target->get_value("financial_code")."'";

    $res = $this->get_db()->query($sql);
    if($res->fetch()){

      $clump = new financial_status_clump;
      $clump->set_db($this->get_db());
      $clump->set_value("id", $res->get_data(0));
      $clump->get();
      $this->set_status($clump);
    }
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_times.txt', date("Y-m-d H:i:s")."=>".$target->get_value("financial_code")."=>1\n", FILE_APPEND);
    
  }

    


  public function phase_analys(){
  	   $sql = "delete from `financial_status` where `trade_date`='0000:00:00'";
    	$res2 = $this->get_db()->query($sql);
  	  
  	  
	$target = $this->get_target();
    $sql = "select * from `setting` limit 1";
    $res2 = $this->get_db()->query($sql);
    if($res2->fetch()){
		$col1 = $res2->get_data(1);
		$col2 = $res2->get_data(2);
		$col3 = $res2->get_data(3);
		$col4 = $res2->get_data(4);
    }
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_date.txt', $target->get_value("financial_code")."=>".date("Y-m-d", $this->get_cal()->get_epoc())."\n", FILE_APPEND);
      $bk_clump = new financial_status_clump;
      $bk_clump->set_db($this->get_db());
      $bk_clump->set_value("trade_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $bk_clump->set_value("financial_code", $target->get_value("financial_code"));
      $bk_clump->get_nopk();
      file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_date.txt', $target->get_value("financial_code")."=>".$bk_clump->get_value("trade_date")."=>".$bk_clump->get_value("status")."\n", FILE_APPEND);
    if($bk_clump->get_value("status") > 0){
	    $clump = new financial_status_clump;
	    $clump->set_db($this->get_db());
	    $clump->set_value("status", $bk_clump->get_value("status"));
	    $clump->set();
    }

    $sql = "select id,financial_code,trade_date,status from financial_status where trade_date = '". date("Y-m-d", $this->get_cal()->get_epoc()). "' and financial_code = '". $target->get_value("financial_code")."'";
    $res = $this->get_db()->query($sql);
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_sql3.txt', $sql."\n", FILE_APPEND);
    if($res->fetch()){
 file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_date.txt', $target->get_value("financial_code")."=>".$res->get_data(2)."=>".$res->get_data(3)."\n", FILE_APPEND);
      $clump = new financial_status_clump;
      $clump->set_db($this->get_db());
      $clump->set_value("id", $res->get_data(0));
      $clump->set_value("financial_code", $res->get_data(1));
      $clump->set_value("trade_date", $res->get_data(2));
      $clump->set_value("status", $res->get_data(3));
      $clump->get();
      $this->set_status($clump);
    }

    $status = $this->get_status();
		file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_st1.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>".$target->get_value("financial_code")."=>".$status->get_value("status")."=>".$bk_clump->get_value("status")."=>1-3\n", FILE_APPEND);
    
	if($status){
		file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_times.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>".$target->get_value("financial_code")."=>".$status->get_value("status")."=>".$bk_clump->get_value("status")."=>1-1\n", FILE_APPEND);
	    switch($status->get_value("status")){
	    case "0":
	      $this->check_0($status,$col1);
	      break;
	    case "1":
	      $this->check_1($status,$col2);
	      break;
	    case "2":
	      $this->check_2($status,$col3);
	      break;
	    case "3":
	      $this->check_3($status,$col4);
	      break;
	    }
	    $this->check_limit($status);

    }else{
    	file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_nostatus.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>".$target->get_value("financial_code")."=>".$status."=>1-2\n", FILE_APPEND);
    	file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_sql3.txt', $sql."\n", FILE_APPEND);

    }
  }

    
  // 20日平均の五倍を記録したらStatus1へシフト
  public function check_0($status,$col1){
    $target = $this->get_target();
    if(0 == $status->get_value("20_days_average")){
      return;
    }

    if($target->get_value("yield_value") > ($status->get_value("20_days_average") * $col1)){
      $this->write_change_log($status->get_value("status"), 1);
      $status->set_value("status", 1);
      $status->set_value("status_0_date", "0000-00-00");
      $status->set_value("status_1_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $status->set_value("status_2_date", "0000-00-00");
      $status->set_value("status_3_date", "0000-00-00");
      $status->set_value("status_4_date", "0000-00-00");
      $status->set();
      $this->set_status($status);
    }
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_times.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>".$target->get_value("financial_code")."=>".$target->get_value("yield_value")."=>".$status->get_value("20_days_average")."*".$col1."=>2\n", FILE_APPEND);
  }

    
  // 条件に該当する終値、日付をゲット
  private function get_final_price($code, $from_date, $to_date){
    $sql = "select end_price, trade_date from daily_financial_price where financial_code = '". $code."' and trade_date < '". $to_date. "' and trade_date > '". $from_date. "' order by trade_date desc limit 1";

    $res = $this->get_db()->query($sql);
    $ret = array();
    if($res->fetch()){
      $ret["end_price"] = $res->get_data(0);
      $ret["trade_date"] = $res->get_data(1);
    }

//print "==========\n";
//print $sql."\n";
//var_dump($ret);
//print "==========\n";
file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_times.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>".$target->get_value("financial_code")."=>3\n", FILE_APPEND);
    return $ret;
  }

    
  // 4日連続負けたらStatus2へシフト
  public function check_1($status,$col2){
    $target = $this->get_target();
    $code = $target->get_value("financial_code");
    
    // status1になる前日値が規準となる
    $sql = "select max(trade_date) from daily_financial_price where trade_date < '". $status->get_value("status_1_date")."'";
    $res = $this->get_db()->query($sql);
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_sql3.txt', $sql."\n", FILE_APPEND);

    if($res->fetch()){
      $yesterday = $res->get_data(0);
    
    $continue = true;
    $rank = 0;
    while($continue){
      // 前日値
      $sql = "select end_price from daily_financial_price where financial_code = '". $code."' and trade_date = '". $yesterday."'";
      $res = $this->get_db()->query($sql);
      if($res->fetch()){
        $yesterday_price = $res->get_data(0);
      }

      // 当日値と当日の日にち
      $sql = "select min(trade_date) from daily_financial_price where financial_code = '". $code. "' and trade_date > '". $yesterday."'";
      $res = $this->get_db()->query($sql);
      if($res->fetch()){
        $today = $res->get_data(0);
      }
      $sql = "select end_price from daily_financial_price where financial_code = '". $code."' and trade_date = '". $today."'";
      $res = $this->get_db()->query($sql);
      if($res->fetch()){
        $today_price = $res->get_data(0);
      }

      if($yesterday_price > $today_price){
        $rank++;
      }elseif($yesterday_price < $today_price){
        $rank = 0;
      }

      if($today == $status->get_value("trade_date")){
        $continue = false;
      }
      $yesterday = $today;
    }
    $status->set_value("rank", $rank);
    $status->set();

    if($rank >= $col2){
      $this->write_change_log($status->get_value("status"), 2);
      $status->set_value("status", 2);
      $status->set_value("status_2_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $status->set();
      $this->set_status($status);
    }
    }
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_times.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>".$target->get_value("financial_code")."=>col2=>".$col2."=>4\n", FILE_APPEND);
  }

    
  // 大出来高記録時の7倍を記録したらStatus3へシフト
  public function check_2($status,$col3){
    $target = $this->get_target();
    $sql = "select yield_value from daily_financial_price where financial_code = '". $target->get_value("financial_code")."' and trade_date = '". $status->get_value("status_1_date")."'";
    $res = $this->get_db()->query($sql);
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_sql3.txt', $sql."\n", FILE_APPEND);

    $status1_yield = 0;
    if($res->fetch()){
      $status1_yield = $res->get_data(0);
    }

    if($target->get_value("yield_value") > ($status1_yield * $col3)){
      $this->write_change_log($status->get_value("status"), 3);
      $status->set_value("status", 3);
      //$this->write_change_log($status->get_value("status"), 4);
      //$status->set_value("status", 4);
      $status->set_value("status_3_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      //$status->set_value("status_4_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $status->set();
      $this->set_status($status);
    }
    file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_times.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>".$target->get_value("financial_code")."=>".$target->get_value("yield_value") ."=>".$status1_yield."*".$col3."=>5\n", FILE_APPEND);
  }

  // Statu3以降で6割勝ち以上を収めたら移動

    
  public function check_3($status,$col4){
    $target = $this->get_target();
    //if($status->get_value("10_days_result") >= 4){
    
   if($status->get_value("10_days_result") >= $col4){
      $this->write_change_log($status->get_value("status"), 4);
      $status->set_value("status", 4);
      $status->set_value("status_4_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $status->set();
      $this->set_status($status);
    }
  file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_times.txt', date("Y-m-d H:i:s", $this->get_cal()->get_epoc())."=>col4=>".$col4."=>6\n", FILE_APPEND);
  }
  
  public function check_limit($status){
    if("0" != $status->get_value("status")){
      $cal = new calendar;
      $cal->set_string($status->get_value("status_". $status->get_value("status") ."_date"));
      $limit = 90;
      //if($status->get_value("status") == 4){
      if($status->get_value("status") >= 4){
        $limit = 1;
      }
      $cal->calculation_day($limit);
      if(date("Ymd", $cal->get_epoc()) < date("Ymd", $this->get_cal()->get_epoc())){
        $this->write_change_log($status->get_value("status"), 0);
        $status->set_value("status", 0);
        $status->set_value("status_0_date", date("Y-m-d", $this->get_cal()->get_epoc()));
        $status->set_value("status_1_date", "0000-00-00");
        $status->set_value("status_2_date", "0000-00-00");
        $status->set_value("status_3_date", "0000-00-00");
        $status->set_value("status_4_date", "0000-00-00");
        $status->set();
        $this->set_status($status);
      }
    }
    
  }

    
  public function write_change_log($before_status, $after_status){
  	 @file_put_contents(dirname(__FILE__).'/log/'.date("Ymd").'_change_log.txt', $this->get_status()->get_value("financial_code")."=>".$this->get_status()->get_value("trade_date")."=>".$before_status."=>". $after_status."\n", FILE_APPEND);

    $log = new status_change_log_clump;
    $log->set_db($this->get_db());
    $log->set_value("financial_code", $this->get_status()->get_value("financial_code"));
    $log->set_value("trade_date", $this->get_status()->get_value("trade_date"));
    $log->set_value("before_status", $before_status);
    $log->set_value("after_status", $after_status);
    $log->set();
  }
}
?>
