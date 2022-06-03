<?php

/**
 * 業務 管理画面用 基底クラス
 *
 *
 * @package magicweapon
 * @link http://www.grid-works-guild.net/MagicWeapon/ MagicWeapon
 * @access  public
 * @author  Michiaki Wuzawa <wuzawa@m-fr.net>
 **/

require_once('common/base_model_base.inc');

abstract class base_model_admin_base extends base_model_base {

// 認証
public function execute()
{
  // 認証チェック
  // インスタンス作って
  $aobj = di::create('admin_authorization');
//var_dump($aobj);

  //
  $aobj->set_clump_name('auth_admin_session_clump');

  // 認証！！
  $r = $aobj->is_auth($this);

  // 駄目ならindexにすっとばす？
  if (false === $r) {
    $this->forward('index');
    return ;
  }
  // else

  $this->get_conv()->set("site_title", $this->get_config()->find("admin_site_title"));

  // OKっぽいので遷移
  return $this->execute_auth();
}

public function is_admin(){

  $ret = false;

  $email = $this->get_bag("user_id");
  $clump = $this->get_clump("users_clump");

  $clump->set_value("email", $email);
  $clump->get_nopk();

  if("" != $clump->get_value("user_id")){
    if(1 == $clump->get_value("authority_flag")){
      $ret = true;
    }
  }
  return $ret;
}

} // end of class

