<?php
/**********************************************************
 * 
 **********************************************************/
set_time_limit(0);

require_once("batch_base.php");
require_once("clump/financial_data_clump.inc");
require_once("clump/comparison_financial_data_clump.inc");


$financial_id = $argv[1];
$class = new fundamental_analys;
$class->set_db($dbh);
$class->analys($financial_id);

exit;
//XXX TEST
$sql = "select financial_id from financial_data order by end_date desc";
$res = $dbh->query($sql);
while($res->fetch()){
  $financial_id = $res->get_data(0);
  $class->init();
  $class->analys($financial_id);
}

class fundamental_analys {

  // 変数
  private $db_;
  

  // アクセッサ〜
  public function set_db($o){ $this->db_ = $o; }
  public function get_db(){ return $this->db_; }

  // 初期化
  public function __construct(){
    $this->db_ = null;
    $this->init();
  }
  public function init(){

  }


  // 処理
  function analys($financial_id){
    $db = $this->get_db();

    $financial = new financial_data_clump;
    $financial->set_db($db);
    $financial->set_value("financial_id", $financial_id);
    if(false == $financial->get()){
      return;
    }
    // これの１個前のデータを探してみる
    $cal = new calendar;
    $cal->set_string($financial->get_value("start_date"));
    $cal->calculation_day(-1);
    $bk_end_date = date("Y-m-d", $cal->get_epoc()); 

    $t1 = new calendar;
    $t1->set_string($financial->get_value("end_date"));
    $t2 = new calendar;
    $t2->set_string($financial->get_value("start_date"));

    $day_span = ceil(($t1->get_epoc() - $t2->get_epoc()) / (60 * 60 * 24));
  
    $t2 = new calendar;
    $t2->set_string($cal->get_string());

    if($day_span > 360){
      // 通年
      $t2->calculation_year(-1);
      $span = 0;
    }else
    if($day_span > 170){
      // 半期
      $t2->calculation_month(-6);
      $span = 1;
    }else{
      // 四半期
      $t2->calculation_month(-3);
      $span = 2;
    }
    $t2->calculation_day(1);
    $bk_start_date = date("Y-m-d", $t2->get_epoc());

    $fin2 = new financial_data_clump;
    $fin2->set_db($db);
    $fin2->set_value("company_code", $financial->get_value("company_code"));
    $fin2->set_value("start_date", $bk_start_date);
    $fin2->set_value("end_date", $bk_end_date);
    $fin2->get_nopk();

    if("" != $fin2->get_value("financial_id")){
      $comp = new comparison_financial_data_clump;
      $comp->set_db($db);
      $comp->set_value("financial_code", $fin2->get_value("company_code"));
      $comp->set_value("span", $span);
      $comp->set_value("start_date", $financial->get_value("start_date"));
      $comp->set_value("end_date", $financial->get_value("end_date"));
      $comp->set_value("comp_net_sales", $financial->get_value("net_sales") - $fin2->get_value("net_sales"));
      $comp->set_value("comp_operating_income", $financial->get_value("operating_income") - $fin2->get_value("operating_income"));
      $comp->set_value("comp_ordinary_income", $financial->get_value("ordinary_income") - $fin2->get_value("ordinary_income"));
      $comp->set_value("comp_net_income", $financial->get_value("net_income") - $fin2->get_value("net_income"));
      $comp->set_value_nowdate("updated_at");

      if( (0 > $financial->get_value("operating_income"))||
          (0 > $financial->get_value("ordinary_income")) ||
          (0 > $financial->get_value("net_income"))){
        $judge = 0; // 利益がどれか一つでもマイナスである => 雨
      }else
      if( (0 < $comp->get_value("comp_net_sales")) && 
          ($financial->get_value("ordinary_income") > ($fin2->get_value("ordinary_income") * 1.1))){
        $judge = 3; // 快晴
      }else
      if( (0 < $financial->get_value("operating_income")) &&
          (0 < $financial->get_value("ordinary_income")) &&
          (0 < $financial->get_value("net_income")) &&
          (0 < $comp->get_value("ordinary_income"))
      ){
        $judge = 2; // 晴れ
      }else{
        $judge = 1; // 曇り
      }
      $comp->set_value("judge", $judge);
      $comp->insert();
    }
  }
}

// end!!
?>
