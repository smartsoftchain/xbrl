<?php

/**
 * 簡易入力フォームに対応させる
 *
 * @package magicweapon
 * @link http://www.grid-works-guild.net/MagicWeapon/ MagicWeapon
 * @access  public
 * @author  Michiaki Wuzawa <wuzawa@m-fr.net>
 **/

require_once('common/base_model_admin_base.inc');

abstract class base_model_admin_extend extends base_model_admin_base {

  protected $clump_;
  protected $jump_url_;

  public function set_jump_url($s){ $this->jump_url_ = $s; }
  public function get_jump_url(){ return $this->jump_url_; }
  public function set_clud_clump($o){ $this->clump_ = $o; }
  public function get_clud_clump(){ return $this->clump_; }


  // 管理者権限持ってない人は管理系機能いけない
  public function execute_auth(){

    $class = get_class($this);
    $tmp = explode("_", $class);
    $action = $tmp[count($tmp)-1];
    unset($tmp[count($tmp)-1]);
    $clump = join("_", $tmp);

    //XXX もうなりふり構わぬ特殊処理
    if($class == "member_input" || $class == "member_fin"){
      $clump = "m_user";
    }
    if($class == "contact_input" || $class == "contact_fin"){
      $clump = "t_contact";
    }


    $clump_name = $clump. "_clump";
    require_once("clump/". $clump_name. ".inc");

    $clump = new $clump_name;
    $clump->set_db($this->get_db());
    $this->set_clud_clump($clump);

    $this->$action();
    $this->execute_extend();
  }

  public function show(){
    $req = $this->get_cgi_request();
    $clump = $this->get_clud_clump();
    $db = $this->get_db();

    $p = $req->find("p") + 0;

    $sql = "select id, title from ". $clump->get_table_name(). " ";
    if("article" == $clump->get_table_name()){
      $sql .= " order by updated_at desc";
    }
    $res = $db->query($sql);

    $data = array();
    while($res->fetch()){
      $tmp = array();
      $tmp["id"] = $res->get_data(0);
      $tmp["title"] = $res->get_data(1);
      $data[] = $tmp;
    }

    $this->get_conv()->set("list", $data);
  }


  public function input(){

    $type_guess = array (
      'TINYINT' => 'int',
      'SMALLINT' => 'int',
      'MEDIUMINT' => 'int',
      'INT' => 'int',
      'INTEGER' => 'int',
      'BIGINT' => 'int',
      'DECIMAL' => 'int',
      'NUMERIC' => 'int',
    
      'FLOAT' => 'float',
      'DOUBLE' => 'float',
      'DOUBLE PRECISION' => 'float',
      'REAL' => 'float',
    
      'DATE' => 'date',
      'DATETIME' => 'date',
      'TIMESTAMP' => 'date',
      'TIME' => 'date',
      'YEAR' => 'date',
    );
    
    

    $clump = $this->get_clud_clump();
    $table = $clump->get_table_name();

    $cobj = $this->get_config();
    $db = db_manager::get_handle( $cobj->find('db_config_path') );
    data_clump_manager::set_dbh($dbh);

    $sql = "show full columns from ". $table;
    $res = $db->query($sql);
    $res->set_fetch_type_hash();

    $cols = array();
    $pk = array();
    while($res->fetch()){
      $awk = array();
      $awk['Field'] = $res->get_data('Field');
      $awk['Type'] = $res->get_data('Type');

      $tmp = explode("|", $res->get_data("Comment"));
      $comment = $tmp[0];
      $desc = array();
      if(2 == count($tmp)){
        $desc = array();
        $tmp = explode(",", $tmp[1]);
        foreach($tmp as $row){
          $row = trim($row);
          list($val, $name) = explode(" ",$row);
          $desc[$val] = $name;
        }
      }

      $awk['Comment'] = $comment;
      $awk["Description"] = $desc;
      $awk['Key'] = $res->get_data('Key');
      // PKチェック：いずれ、uniqueとかもやりたいねぇ
      if ( 0 === strcasecmp('PRI', $awk['Key']) ) {
        $pk[$awk['Field']] = 'pk';
        $awk['Key'] = 'pk';
      }
      // Typeの判定
      // XXX ちょいとべただねぇ…
      list($type, $dummy) = explode('(', $awk['Type'], 2);
      $type = strtoupper($type);
      // 推測
      if (true === isset($type_guess[$type])) {
        $type_string = $type_guess[$type];
      } else {
        $type_string = 'string';;
      }
      // XXX いったんベタで文字列保持
      switch($type_string) {
        case 'int':
          $s = 'DATATYPE_INT';
          break;

        case 'string':
          $s = 'DATATYPE_STRING';
          break;

        case 'date':
          $s = 'DATATYPE_DATE';
          break;

        case 'float':
          $s = 'DATATYPE_FLOAT';
          break;

        default: // XXX 念のため
          $s = 'DATATYPE_STRING';
          break;
      }
      $awk["TypeString"] = $s;
      $cols[] = $awk;
    }

    foreach($pk as $k => $p){
      $clump->set_value($k, $this->get_cgi_request()->find($k));
    }
    $clump->get();

    $this->get_conv()->set("clump", $clump);
    $this->get_conv()->assign_unsecure_raw("cols", $cols);
  }

  public function fin(){
    $clump = $this->get_clud_clump();
    $req = $this->get_cgi_request();
    $db = $this->get_db();

    $id = $req->find("id");
    if(true === empty($id)){
      $sql = "select max(id) as cnt from ". $clump->get_table_name();
      $res = $db->query($sql);
      while($res->fetch()){
        $id = $res->get_data(0);
      }
      $id++;
    }
    $clump->set_value("id", $id);
    $clump->get();


    foreach($clump->get_all_names() as $key){
      if("id" == $key){ continue; } // IDは最初にセットしちゃう
      // photoのalt
      if(false !== strstr($key, "photo_alt")){
        $no = str_replace("photo_alt_", "", $key);
        $clump->set_value($key, $req->find($key));
        if("1" == $req->find("photo_". $no. "_del")){
          $clump->set_value($key, "");
        }
      }else
      if(false !== strstr($key, "photo_")){
      // photoそのもの
        $no = str_replace("photo_", "", $key);
        $no = str_replace("alt_", "", $no);
        $move_to = $this->get_config()->find("photo_dir"). $clump->get_table_name(). "/". $clump->get_value("id"); 

        if("1" == $req->find("photo_". $no. "_del")){
          unlink($move_to. "/". $clump->get_value($key));
          $clump->set_value($key, "");
        }else if(true == is_uploaded_file($_FILES[$key]['tmp_name'])){
          $move_to = $this->get_config()->find("photo_dir"). $clump->get_table_name(). "/". $clump->get_value("id"); 
          $filename = $_FILES[$key]["name"];
          $ext = preg_replace('/^.*\.([^.]+)$/D', '$1', $filename);
          $new_filename = $key. ".". $ext;

          if(false == file_exists($move_to)){
            mkdir($move_to);
          }
          move_uploaded_file($_FILES[$key]["tmp_name"], $move_to. "/". $new_filename);
          $clump->set_value($key, $new_filename);
        }
      }else
      if("category_ids" == $key){
        $tmp = $req->find("category_ids");
        $tmp = explode(",", $tmp);
        $val = "";
        foreach($tmp as $cid){
          $val .= " ". $cid. " ,";
        }
        $clump->set_value($key, $val);
      }else{
        $clump->set_value($key, $req->find($key));
      }
    }

    $clump->set();

    $jump_url = "admin.php?c=". $clump->get_table_name(). "_show";
    $this->set_jump_url($jump_url);
  }

  public function del(){
    $clump = $this->get_clud_clump();
    $req = $this->get_cgi_request();
    $db = $this->get_db();
    $id = $req->find("id");

    $clump->set_value("id", $id);
    $clump->get();
    $clump->del();

    $jump_url = "admin.php?c=". $clump->get_table_name(). "_show";
    header("Location: ". $jump_url);
    exit;
  }

  abstract public function execute_extend();

} // end of class

