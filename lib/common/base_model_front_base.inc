<?php

/**
 * 業務 フロント用 基底クラス
 *
 *
 * @package magicweapon
 * @link http://www.grid-works-guild.net/MagicWeapon/ MagicWeapon
 * @access  public
 * @author  Michiaki Wuzawa <wuzawa@m-fr.net>
 **/

require_once('common/base_model_base.inc');

abstract class base_model_front_base extends base_model_base {

//
public function initialize()
{
  //
  parent::initialize();

  // URL用の設定
  // XXX ここでやる？
  $conv = $this->get_conv();

  $this->get_conv()->set("site_title", $this->get_config()->find("site_title"));
}

// 認証
public function execute()
{
  //
  return $this->execute_auth();
}

} // end of class

