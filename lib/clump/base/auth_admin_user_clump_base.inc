<?php
/*
 * admin用の認証テーブル 用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class auth_admin_user_clump_base extends data_clump {

public function __construct()
{
  parent::__construct();
}

public function init()
{
  parent::init();
  $this->set_element();	// ユーザ登録画面の要素を登録
}

/**
 * 基本的な情報の設定
 *
 * テーブル名およびカラム名を設定する
 *
 * @access protected
 * @return boolean falseは現状想定外。
 */
protected function set_element()
{
  //
  $this->set_table_name('auth_admin_user');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_STRING); // ログイン用ID込みのID(varbinary(64))
  $this->push_element('pass', '', '', '', '', data_clump::DATATYPE_STRING); // パスワード。適宜salted hash＆ストレッチ(blob)
  $this->push_element('pass_raw', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('status', '', '', '', '', data_clump::DATATYPE_STRING); // ステータス。基本未使用、ロール管理などに使える領域(varbinary(8))
  $this->push_element('lock_time', '', '', '', '', data_clump::DATATYPE_INT); // ここが０でない場合、エポック秒でここの時間まではログイン不可(bigint(20))
  $this->push_element('err_count', '', '', '', '', data_clump::DATATYPE_INT); // ログインエラーの回数。一定回数でlock_timeに時間を設定する(int(11))


}

//private:


} // end of class



