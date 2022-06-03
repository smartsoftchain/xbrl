<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class user_clump_base extends data_clump {

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
  $this->set_table_name('user');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_INT); // ユーザID(int(11) unsigned)
  $this->push_element('pass', '', '', '', '', data_clump::DATATYPE_STRING); // パスワード(varchar(256))
  $this->push_element('name', '', '', '', '', data_clump::DATATYPE_STRING); // 名前（漢字）(varchar(32))
  $this->push_element('mail', '', '', '', '', data_clump::DATATYPE_STRING); // メールアドレス(varchar(255))
  $this->push_element('status', '', '', '', '', data_clump::DATATYPE_INT); // ステータス 0:利用可 1:利用不可(int(2) unsigned)
  $this->push_element('update_date', '', '', '', '', data_clump::DATATYPE_DATE); // 更新日付(date)


}

//private:


} // end of class



