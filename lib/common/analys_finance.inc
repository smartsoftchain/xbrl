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


    // 20日平均出来高
    $sql = "select yield_value, end_price, trade_date, financial_code from daily_financial_price where financial_code = '". $target->get_value("financial_code")."' and trade_date < '". date("Y-m-d", $this->get_cal()->get_epoc()). "' order by trade_date desc limit 20";
    $res = $this->get_db()->query($sql);
    $i=0;
    $result = 0;
    $result2 = 0;
    $sum = 0;

    $tmp = array();
    $bk = 0;

    while($res->fetch()){
      if(0 == $i){
        $trade_date = $res->get_data(2);
        $financial_code = $res->get_data(3);
      }

      $yield = $res->get_data(0);
      $end_price = $res->get_data(1);

      $sum += $yield;

      // 10日の結果
      if($i < 10){
        $tmp[] = $end_price;
      }
      if($i == 10){
        $bk = $end_price;
      }
      $i++;
    }
    $tmp = array_reverse($tmp);
    foreach($tmp as $ep){
      if($bk < $ep){
        $result++;
      }else{
        //$result--;
        $result2++;
      }
      $bk = $ep;
    }

    if($sum > 0){
      $heikin = round($sum / $i, 2);
    }else{
      $heikin = 0;
    }
    $clump = new financial_status_clump;
    $clump->set_db($this->get_db());
    $clump->set_value("newest_flg", 1);
    $clump->set_value("trade_date", date("Y-m-d", $this->get_cal()->get_epoc()));
    $clump->set_value("financial_code", $target->get_value("financial_code"));
    if($i > 0){
      $bk_clump = new financial_status_clump;
      $bk_clump->set_db($this->get_db());
      $bk_clump->set_value("trade_date", $trade_date);
      $bk_clump->set_value("financial_code", $financial_code);
      $bk_clump->get_nopk();
      $bk_status = 0;
 file_put_contents('/var/www/html/xbrl/batch/log/'.date("Ymd").'_statuslog1.txt', $financial_code."=>".$bk_clump->get_value("status")."\n", FILE_APPEND);
      if("" != $bk_clump->get_value("id")){
        $clump->set_value("status", $bk_clump->get_value("status"));
        $clump->set_value("status_0_date", $bk_clump->get_value("status_0_date"));
        $clump->set_value("status_1_date", $bk_clump->get_value("status_1_date"));
        $clump->set_value("status_2_date", $bk_clump->get_value("status_2_date"));
        $clump->set_value("status_3_date", $bk_clump->get_value("status_3_date"));
        $clump->set_value("status_4_date", $bk_clump->get_value("status_4_date"));
      }
    }
//    $sql = "update financial_status set newest_flg = 0 where financial_code = '". $target->get_value("financial_code")."'";
//    $this->get_db()->query($sql);

    $clump->set_value("20_days_average", $heikin);
    $clump->set_value("10_days_result", $result);
    $clump->set_value("10_days_result2", $result2);
    $clump->set();
    $clump->get_nopk();
    
//echo $financial_code."=>".$trade_date."==>Result=>".$result."==>Result2=>".$result2."\n";

    $sql = "select id from financial_status where trade_date = '". date("Y-m-d", $this->get_cal()->get_epoc()). "' and financial_code = '". $target->get_value("financial_code")."'";
    $res = $this->get_db()->query($sql);
    if($res->fetch()){

      $clump = new financial_status_clump;
      $clump->set_db($this->get_db());
      $clump->set_value("id", $res->get_data(0));
      $clump->get();
      $this->set_status($clump);
    }
  }

  public function phase_analys(){
    $status = $this->get_status();
file_put_contents('/var/www/html/xbrl/batch/log/'.date("Ymd").'_statuslog.txt', $financial_code."=>".$status->get_value("status")."\n", FILE_APPEND);
    switch($status->get_value("status")){
    case "0":
      $this->check_0($status);
      break;
    case "1":
      $this->check_1($status);
      break;
    case "2":
      $this->check_2($status);
      break;
    case "3":
      $this->check_3($status);
      break;
    }
    $this->check_limit($status);
  }

  // 20日平均の五倍を記録したらStatus1へシフト
  public function check_0($status){
    $target = $this->get_target();
    if(0 == $status->get_value("20_days_average")){
      return;
    }

    if($target->get_value("yield_value") > ($status->get_value("20_days_average") * 5)){
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

    return $ret;
  }

  // 4日連続負けたらStatus2へシフト
  public function check_1($status){
    $target = $this->get_target();
    $code = $target->get_value("financial_code");
    
    // status1になる前日値が規準となる
    $sql = "select max(trade_date) from daily_financial_price where trade_date < '". $status->get_value("status_1_date")."'";
    $res = $this->get_db()->query($sql);

    if($res->fetch()){
      $yesterday = $res->get_data(0);
    }
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

    if($rank >= 4){
      $this->write_change_log($status->get_value("status"), 2);
      $status->set_value("status", 2);
      $status->set_value("status_2_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $status->set();
      $this->set_status($status);
    }
  }

  // 大出来高記録時の7倍を記録したらStatus3へシフト
  public function check_2($status){
    $target = $this->get_target();
    $sql = "select yield_value from daily_financial_price where financial_code = '". $target->get_value("financial_code")."' and trade_date = '". $status->get_value("status_1_date")."'";
    $res = $this->get_db()->query($sql);

    $status1_yield = 0;
    if($res->fetch()){
      $status1_yield = $res->get_data(0);
    }

    if($target->get_value("yield_value") > ($status1_yield * 7)){
      $this->write_change_log($status->get_value("status"), 3);
      $status->set_value("status", 3);
      //$this->write_change_log($status->get_value("status"), 4);
      //$status->set_value("status", 4);
      $status->set_value("status_3_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      //$status->set_value("status_4_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $status->set();
      $this->set_status($status);
    }
  }

  // Statu3以降で6割勝ち以上を収めたら移動

  public function check_3($status){
    $target = $this->get_target();
    //if($status->get_value("10_days_result") >= 4){
    
   if($status->get_value("10_days_result") >= 6){
      $this->write_change_log($status->get_value("status"), 4);
      $status->set_value("status", 4);
      $status->set_value("status_4_date", date("Y-m-d", $this->get_cal()->get_epoc()));
      $status->set();
      $this->set_status($status);
    }
  
  }
  
  public function check_limit($status){
    if("0" != $status->get_value("status")){
      $cal = new calendar;
      $cal->set_string($status->get_value("status_". $status->get_value("status") ."_date"));
      $limit = 90;
      if($status->get_value("status") == 4){
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
