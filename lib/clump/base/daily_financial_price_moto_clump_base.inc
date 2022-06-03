<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class daily_financial_price_moto_clump_base extends data_clump {

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
  $this->set_table_name('daily_financial_price_moto');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('trade_date', '', '', '', 'pk', data_clump::DATATYPE_DATE); // (date)
  $this->push_element('financial_code', '', '', '', 'pk', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('company_name', '', '', '', '', data_clump::DATATYPE_STRING); // (varchar(255))
  $this->push_element('start_price', '', '', '', 'MUL', data_clump::DATATYPE_INT); // 始値(int(10) unsigned)
  $this->push_element('end_price', '', '', '', '', data_clump::DATATYPE_INT); // 終値(int(10))
  $this->push_element('high_price', '', '', '', '', data_clump::DATATYPE_INT); // 高値(int(10) unsigned)
  $this->push_element('low_price', '', '', '', '', data_clump::DATATYPE_INT); // 安値(int(10) unsigned)
  $this->push_element('yield_value', '', '', '', '', data_clump::DATATYPE_FLOAT); // 出来高(単位1000)(float(10,4) unsigned)


}

//private:


} // end of class



