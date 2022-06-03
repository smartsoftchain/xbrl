<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class search_focus2_clump_base extends data_clump {

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
  $this->set_table_name('search_focus2');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_INT); // (int(11) unsigned)
  $this->push_element('new_flg', '', '', '', '', data_clump::DATATYPE_INT); // 0 インサートされたばかりのデータ, 1 最新, 2 消される直前のデータ(見る機会は限りなく少ない)(tinyint(1) unsigned)
  $this->push_element('column1', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column2', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column3', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column4', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column5', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column6', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column7', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column8', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('column9', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('created_at', '', '', '', '', data_clump::DATATYPE_DATE); // (datetime)


}

//private:


} // end of class



