<?php

/**
 * 業務全体基底クラス
 *
 *
 * @package magicweapon
 * @link http://www.grid-works-guild.net/MagicWeapon/ MagicWeapon
 * @access  public
 * @author  Michiaki Wuzawa <wuzawa@m-fr.net>
 **/

require_once('base_model_base.inc');
require_once("common/auth.inc");
require_once("common/util.inc");

abstract class base_model_ambiguous extends base_model_base {

  private $is_auth_;
  protected $member_;

  public function __construct(){
    parent::__construct();
  }

  public function execute(){
    util::set_db($this->get_db());

    if(false == in_array(get_class($this), array("login", "index", "top", "password"))){
      $this->authentics();
    }
    if("top" == get_class($this)){
      if(isset($_POST["id"]) && isset($_POST["pw"])){
        $id = $_POST["id"];
        $pw = md5($_POST["pw"]);
      }else{
        $id = @$_COOKIE["bi"];
        $pw = @$_COOKIE["bp"];
      }
      $auth = new auth;
      $auth->set_conf($this->get_config());
      $auth->set_db($this->get_db());
      $this->is_auth_ = $auth->login($id, $pw);
    }


    if(false == $this->is_auth()){
      header("Location: index.php");
      exit;
      return;
    }
  } 

  public function is_auth(){
    return $this->is_auth_;
  }

  public function authentics(){
    $auth = new auth;
    $auth->set_conf($this->get_config());
    $auth->set_db($this->get_db());
    $this->is_auth_ = $auth->check_auth();
  }

  public function get_user_info(){
    $member = null;
    if(true == $this->is_auth()){
      $id = @$_COOKIE["bi"];
      if(empty($id)){
        $id = $_POST["id"];
      }
      $member = $this->get_clump("user_clump");
      $member->set_value("mail", $id);
      $member->get_nopk();
    }
    return $member;
  }

  public function get_clump($clump, $obj=null){
    $file_name = $clump. ".inc";
    require_once("clump/". $file_name);
    return parent::get_clump($clump, $obj);
  }

} // end of class


