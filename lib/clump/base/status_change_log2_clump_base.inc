<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class status_change_log2_clump_base extends data_clump {

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
  $this->set_table_name('status_change_log2');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_INT); // (bigint(20) unsigned)
  $this->push_element('financial_code', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(32))
  $this->push_element('trade_date', '', '', '', '', data_clump::DATATYPE_DATE); // (date)
  $this->push_element('before_status', '', '', '', '', data_clump::DATATYPE_INT); // (tinyint(4))
  $this->push_element('after_status', '', '', '', '', data_clump::DATATYPE_INT); // (tinyint(4))


}

//private:


} // end of class



