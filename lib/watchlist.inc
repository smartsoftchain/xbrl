<?php

/***************************************************
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_ambiguous.inc');
require_once('common/util.inc');

class watchlist extends base_model_ambiguous {

  //処理
  public function execute() {
    parent::execute();

    //リクエスト
    $req = $this->get_cgi_request();
    $smarty = $this->get_conv();
    $db = $this->get_data_db();

    // 表示させる項目
    $user = $this->get_user_info();
    $sql = "select financial_code, scene, created_at from clip where user_id = '". $user->get_value("id")."'";

    $res = $this->get_db()->query($sql);
    $codes = array();
    while($res->fetch()){
      $tmp = array();
      $tmp["scene"] = $res->get_data(1);
      $tmp["created_at"] = $res->get_data(2);
      $codes[$res->get_data(0)] = $tmp;
    }

    $sql = "select max(trade_date) from financial_status";
    $res = $db->query($sql);
    if($res->fetch()){
      $max_date = $res->get_data(0);
    }

    $datum1 = array();
    $datum2 = array();
    $datum3 = array();

    foreach($codes as $code => $clip_data){
      $sobj = $this->get_clump("financial_status_clump");
      $sobj->set_db($db);
      $sobj->set_value("financial_code", $code);
      $sobj->set_value("trade_date", $max_date);
      $sobj->get_nopk();
      if("" == $sobj->get_value("id")){
        continue;
      }

      $dobj = $this->get_clump("daily_financial_price_clump");
      $dobj->set_db($db);
      $dobj->set_value("financial_code", $code);
      $dobj->set_value("trade_date", $max_date);
      if(false == $dobj->get()){
        continue;
      }
      $cal = new calendar;
      $cal->set_string($clip_data["created_at"]);

      $bk_end_price = 0;
      $sql = "select end_price from daily_financial_price where financial_code = '". $code. "' and trade_date < '". date("Y-m-d", $cal->get_epoc())."' order by trade_date desc limit 1";
      $res = $db->query($sql);
      if($res->fetch()){ $bk_end_price = $res->get_data(0); }

      $tenki = 1;
      $sql = "select judge from comparison_financial_data where financial_code = '". $code."' order by end_date desc, id desc limit 1";
      $res = $db->query($sql);
      if($res->fetch()){
        $tenki = $res->get_data(0);
      }

      $data = array();
      $data["name"] = $dobj->get_value("company_name");
      $data["code"] = $code;
      $data["now"] = $dobj->get_value("end_price");
      $data["before"] = $bk_end_price;
      $data["clip_date"] = date("Y/m/d", $cal->get_epoc());
      $data["tenki"] = $tenki;


      switch($sobj->get_value("status")){
      case "1": // 大出来高
        $cal2 = new calendar;
        $cal2->set_now_date();

//        $sql = "select end_price from daily_financial_price where financial_code = '". $sobj->get_value("financial_code")."' and trade_date >= '". $sobj->get_value("sobj_1_date")."' and trade_date <= '". date("Y-m-d", $cal2->get_epoc())."' order by trade_date desc limit 6";


        $sql = "select id, column1, column2, column3, column4, column5, column6, column7, column8, created_at from search_focus where column2 = '". $sobj->get_value("financial_code"). "'";

        $res = $db->query($sql);
        while($res->fetch()){
		      $tmp = array();
		      $tmp["dekidaka_rate"] = $res->get_data(1);
		      $tmp["financial_code"] = $res->get_data(2);
		      $tmp["company_name"] = $res->get_data(3);
		      $tmp["end_price"] = $res->get_data(4);
		      $tmp["rate"] = $res->get_data(5);
		      $tmp["record_date"] = $res->get_data(6);
		      $tmp["rank"] = $res->get_data(7);
		      $tmp["cliped"] = util::is_clip($user->get_value("id"), $res->get_data(2));
        }
 
        $data["result"] = $tmp["rank"];
        $data["rankup_date"] = str_replace("-", "/", $sobj->get_value("status_1_date"));
        $datum2[] = $data; 
        break;
      case "2": // 押し目買い
        $data["rankup_date"] = str_replace("-", "/", $sobj->get_value("status_2_date"));
        $data["handan"] = "サイン未出現";
        $datum1[] = $data;
        break;
      case "3": // 特大出来高
        $data["rankup_date"] = str_replace("-", "/", $sobj->get_value("status_2_date"));
        $data["handan"] = "サイン未出現";
        $datum1[] = $data;
        break;
      case "4": // 売サイン
        $data["rankup_date"] = str_replace("-", "/", $sobj->get_value("status_2_date"));
        $data["handan"] = str_replace("-", "/", $sobj->get_value("status_4_date"));
        $datum1[] = $data;
        break;
      }

      if("2" == $clip_data["scene"]){
        $data["rankup_date"] = "注目銘柄登録されていません";
        if(0 != $sobj->get_value("status")){
          $data["rankup_date"] = str_replace("-", "/", $sobj->get_value("status_1_date"));
        }
        $datum3[] = $data;
      }
    }
    $smarty->set("datum1", $datum1);
    $smarty->set("datum2", $datum2);
    $smarty->set("datum3", $datum3);
  }

} // end of class
