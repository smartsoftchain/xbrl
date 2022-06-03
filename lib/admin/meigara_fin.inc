<?php

/***************************************************
 * ログイン後トップ画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('base_model_admin_base.inc');
require_once("calendar.inc");

class meigara_fin extends base_model_admin_base {

  //処理
  public function execute_auth() {
    //リクエスト
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $smarty = $this->get_conv();
    
    //
    $type = $req->find("type");
    $meigara = $this->get_clump("meigara_clump");

    if($type == "data"){
      $mode = $req->find("mode");
      if("add" == $mode){
        $code = $req->find("financial_code");
        $name = $req->find("name");
        $market_flg = $req->find("market_flg");

        $meigara->set_value("financial_code", $code);
        $meigara->set_value("name", $name);
        $meigara->set_value("market_flg", $market_flg);
        $meigara->set_value_nowdate("created_at");
        $meigara->set();
      }else
      if("del" == $mode){
        $code = $req->find("financial_code");
        $meigara->set_value("financial_code", $code);
        if($meigara->get()){
          $meigara->del();
        }
      }
    }else
    if($type == "csv"){
      if (is_uploaded_file($_FILES["csv"]["tmp_name"])) {
        $csv = $req->get_file("csv");
        $csv = mb_convert_encoding($csv, "utf-8", "SJIS");
        $rows = explode("\n", $csv);
        foreach($rows as $row){
          $columns = explode(",", $row);
          $market_flg = trim($columns[0]);
          $code = trim($columns[1]);
          $name = trim($columns[2]);
          $mode = trim($columns[3]);

          if("1" == $mode){ // add, edit
            $meigara->set_value("financial_code", $code);
            $meigara->set_value("name", $name);
            $meigara->set_value("market_flg", $market_flg);
            $meigara->set_value_nowdate("created_at");
            $meigara->set();
          }else
          if("0" == $mode){ // del
            $meigara->set_value("financial_code", $code);
            if($meigara->get()){
              $meigara->del();
            }
          }
        }
      }
    }
    $this->redirect("admin.php?c=meigara");
    return;
  }
} // end of class


