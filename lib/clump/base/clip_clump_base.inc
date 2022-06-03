<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class clip_clump_base extends data_clump {

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
  $this->set_table_name('clip');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('user_id', '', '', '', 'pk', data_clump::DATATYPE_INT); // (bigint(20))
  $this->push_element('financial_code', '', '', '', 'pk', data_clump::DATATYPE_STRING); // (varchar(64))
  $this->push_element('scene', '', '', '', '', data_clump::DATATYPE_INT); // どこから追加されたのか 0:注目 1:最注目 2:急上昇(tinyint(1))
  $this->push_element('created_at', '', '', '', '', data_clump::DATATYPE_DATE); // (datetime)


}

//private:


} // end of class



