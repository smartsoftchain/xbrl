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

require_once('base_model.inc');

abstract class base_model_base extends base_model {

  private $ignore_list_;
  private $data_db_;

  public function get_clump($clump, $obj=null){
    $file_name = $clump. ".inc";
    require_once("clump/". $file_name);
    return parent::get_clump($clump, $obj);
  }

  public function get_data_db(){
    if($this->data_db_ == null){
      $db = new dbh_pdo_mysql;
      $db->set_user("root");
      $db->set_pass("06110204");
      $db->set_host_name("localhost");
      $db->set_database_name("sfntoushi");
      if($db->connect()){
        $this->data_db_ = $db;
      }
    }
    return $this->data_db_;
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
} // end of class

