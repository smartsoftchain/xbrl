<?php
require_once("clump/user_clump.inc");

class auth{

  // 変数部
  private $conf_;
  private $db_;

  // アクセサー
  public function set_conf($o){ $this->conf_ = $o; }
  public function get_conf(){ return $this->conf_; }
  public function set_db($o){ $this->db_ = $o; }
  public function get_db(){ return $this->db_; }

  // 初期化
  public function __construct(){
    $this->init();
  }
  public function init(){
    $this->conf_ = null;
  }

  // ログインチェック
  public function login($id, $pw){
    $sql = "select pass from user where mail = '". $id. "' and status=0";
    $res = $this->get_db()->query($sql);
    $pass = "";
    if($res->fetch()){
      $pass = $res->get_data(0);
    }

    $auth = false;
    if("" != $pass){
      if(md5($pass) === $pw){
        setcookie("bi", $id);
        setcookie("bp", $pw);
        $auth = true;
      }
    }
    return $auth;
  }

  // ログイン後の認証チェック
  public function check_auth(){
    $id = @$_COOKIE["bi"];
    $pw = @$_COOKIE["bp"];

    return $this->login($id, $pw);
  }

}
?>
