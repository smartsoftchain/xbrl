<?php

/***************************************************
 * ログイン画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('base_model_admin_base.inc');
require_once('clump/auth_admin_user_clump.inc');
require_once('conv_util.inc');

class login extends base_model_admin_base {

//処理
public function execute() {
//print "Trap 1\n";
  //
  $req = $this->get_cgi_request();
  $conv = $this->get_conv();

  //
  $obj = di::create('admin_authentication');
//var_dump($obj);

  // IDとパスワードを設定
  $id = $req->find('id');
  $conv->monoDic('id', $id);
  $obj->set_id($id);
  $obj->set_raw_password($req->find('pass'));

  //
  $obj->set_authentication_clump( $this->get_clump('auth_admin_user_clump') );

  //
  $r = $obj->login();

  //
  if (false === $r) {
    // エラーの意を表明して
    $conv->multiDic('is_login_error', new simple_put());
    // top pageに突っ返す
    $this->forward('index');
    //
    return ;
  }
  // else
  // セッション作って
  $aobj = di::create('admin_authorization');
  $aobj->set_clump_name('auth_admin_session_clump');
  $aobj->auth_on($id, $this);

  // location
  $this->redirect('./admin.php?c=top');
}

} // end of class

