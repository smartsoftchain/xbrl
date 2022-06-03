<?php
class util{

  static private $db_;

  static public function set_db($o){ self::$db_ = $o; }
  static public function get_db(){ return self::$db_; }

  static public function is_clip($user_id, $financial_code){
    require_once("clump/clip_clump.inc");
    $clip = new clip_clump;
    $clip->set_db(self::get_db());
    $clip->set_value("user_id", $user_id);
    $clip->set_value("financial_code", $financial_code);
    if($clip->get()){
      return true;
    }
    return false; 
  }

//顧客コード生成ロジック
  static public function __get_string_list(){
    $strings = array(  0 => "A", 1 => "B", 2 => "C", 3 => "D", 4 => "E",
                       5 => "F", 6 => "G", 7 => "H", 8 => "I", 9 => "J",
                      "a"=> "K","b"=> "L","c"=> "M","d"=> "N","e"=> "O",
                      "f"=> "P","g"=> "R","h"=> "S","i"=> "T","j"=> "U",
                      "k"=> "V","l"=> "W","m"=> "X","n"=> "Y","o"=> "Z");
    return $strings;
  }

  static public function create_contract_code($id){
    //桁数決め打ち
    $long = 10;
    $separator = "Q";
    $strings = self::__get_string_list();

    $conv = base_convert($id, 10, 25);

    $ret = "";
    for($i=0; $i<strlen($conv); $i++){
      $c = $conv[$i];
      $ret .= $strings[$c];
    }
    $zan = $long - strlen($ret) - 1;
    $pad = "";
    for($i=0; $i<$zan; $i++){
      $idx = rand(0, 25);
      $idx = base_convert($idx, 10, 25);
      if(2 == strlen($idx)){
        $idx = $idx[0];
      }
      $pad .= $strings[$idx];
    }
   
    return $pad. $separator. $ret;
  }

  static public function calc_oodekidaka_rate($sobj){
    $db = $sobj->get_db();
    $date = $sobj->get_value("status_1_date");
    $code = $sobj->get_value("financial_code");

    $bk_sobj = clone $sobj;
    $bk_sobj->init();
    $bk_sobj->set_db($db);
    $bk_sobj->set_value("trade_date", $date);
    $bk_sobj->set_value("financial_code", $code);
    $bk_sobj->get_nopk();

    $sql = "select yield_value from daily_financial_price where financial_code = '". $code."' and trade_date = '". $date."' order by trade_date desc limit 1";
    $res = $db->query($sql);
    $value = 0;
    if($res->fetch()){
      $value = $res->get_data(0);
    }
    if(0 == $bk_sobj->get_value("20_days_average")){
      $rate = "--";
      return $rate;
    }

/*
print $code."  ";
var_dump($value);
var_dump($bk_sobj->get_value("20_days_average"));
print "<hr>";
*/
    $rate = round($value / $bk_sobj->get_value("20_days_average"), 1);
    return $rate;
  }
}
?>
