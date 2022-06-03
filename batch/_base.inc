<?php
set_time_limit(0);

require_once("batch_base.php");
require_once("common/util.inc");

class base{
  protected $table_name_;
  protected $db_;
  protected $ignore_list_;

  //
  public function set_table_name($s){ $this->table_name_ = $s; }
  public function get_table_name(){ return $this->table_name_; }
  public function set_db($o){ $this->db_ = $o; }
  public function get_db(){ return $this->db_; }

  // 
  public function __construct(){
    $this->init();
  }
  public function init(){
    $this->table_name_;
  }

  // 便利なメソッドまとめておく
  public function get_clump($clump_name){
    require_once("clump/". $clump_name. ".inc");
    $clump = new $clump_name;
    $clump->set_db($this->get_db());
    return $clump;
  }

  public function change_version(){
    $sql = "update ". $this->get_table_name(). " set new_flg = new_flg + 1";
    $this->get_db()->query($sql);
    $sql = "delete from ". $this->get_table_name(). " where new_flg = 2";
    $this->get_db()->query($sql);
  }

  public function get_ignore_list(){
    if($this->ignore_list_ != null){
      return $this->ignore_list_;
    }
    $sql = "select financial_code from ignore_list";
    $res = $this->get_db()->query($sql);

    $this->ignore_list_ = array();
    while($res->fetch()){
      $this->ignore_list_[] = $res->get_data(0);
    }
    return $this->ignore_list_;
  }

  // 条件に該当する終値、日付をゲット
  protected function get_final_price($code, $from_date, $to_date){
    $sql = "select end_price, trade_date from daily_financial_price where financial_code = '". $code."' and trade_date < '". $to_date. "' and trade_date > '". $from_date. "' order by trade_date desc limit 1";

    $res = $this->get_db()->query($sql);
    $ret = array();
    if($res->fetch()){
      $ret["end_price"] = $res->get_data(0);
      $ret["trade_date"] = $res->get_data(1);
    }
    return $ret;
  }




}
?>
