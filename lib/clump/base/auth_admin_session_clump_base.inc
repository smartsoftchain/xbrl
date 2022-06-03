<?php
/*
 * admin用セッションID格納テーブル 用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class auth_admin_session_clump_base extends data_clump {

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
  $this->set_table_name('auth_admin_session');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', '', data_clump::DATATYPE_STRING); // adminのユーザID。１ユーザで複数セッションIDを許可しているので、PKではない。(varbinary(64))
  $this->push_element('sid', '', '', '', 'pk', data_clump::DATATYPE_STRING); // セッションID。基本的にはdifficulty imagining IDを想定。(varbinary(255))
  $this->push_element('expire', '', '', '', '', data_clump::DATATYPE_INT); // セッションの有効寿命。値はエピック秒。(bigint(20))


}

//private:


} // end of class



