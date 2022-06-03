<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class financial_data_clump_base extends data_clump {

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
  $this->set_table_name('financial_data');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('financial_id', '', '', '', 'pk', data_clump::DATATYPE_INT); // (bigint(20) unsigned)
  $this->push_element('company_code', '', '', '', '', data_clump::DATATYPE_INT); // 証券コード(decimal(6,0))
  $this->push_element('company_name', '', '', '', '', data_clump::DATATYPE_STRING); // 会社名(varchar(200))
  $this->push_element('start_date', '', '', '', '', data_clump::DATATYPE_DATE); // 決済範囲 開始日(date)
  $this->push_element('end_date', '', '', '', '', data_clump::DATATYPE_DATE); // 決済範囲 終了日(date)
  $this->push_element('net_sales', '', '', '', '', data_clump::DATATYPE_INT); // 売上高(decimal(10,2))
  $this->push_element('operating_income', '', '', '', '', data_clump::DATATYPE_INT); // 今期営業利益(decimal(10,2))
  $this->push_element('ordinary_income', '', '', '', '', data_clump::DATATYPE_INT); // 今期経常利益(decimal(10,2))
  $this->push_element('net_income', '', '', '', '', data_clump::DATATYPE_INT); // 今期純利益(decimal(10,2))
  $this->push_element('analysis_date', '', '', '', '', data_clump::DATATYPE_DATE); // (datetime)
  $this->push_element('file_name', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(200))


}

//private:


} // end of class



