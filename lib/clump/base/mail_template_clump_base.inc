<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class mail_template_clump_base extends data_clump {

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
  $this->set_table_name('mail_template');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_INT); // (int(10) unsigned)
  $this->push_element('type', '', '', '', '', data_clump::DATATYPE_INT); // 0:買い送信用  1:売り送信用(tinyint(1) unsigned)
  $this->push_element('subject', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(512))
  $this->push_element('body', '', '', '', '', data_clump::DATATYPE_STRING); // (text)
  $this->push_element('from_address', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('from_name', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))


}

//private:


} // end of class



