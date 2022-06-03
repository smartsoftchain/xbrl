<?php
/*
 * サンプル用
 *
 */


require_once("data_clump.inc");

class daily_financial_price_clump extends data_clump {

public function __construct()
{
  //$this->init();
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
  $this->set_table_name('daily_financial_price');

  // $inname, $cginame, $tmpname, $dbname, $keyflg
  $this->push_element('trade_date', '', '', '', 'pk');
  $this->push_element('financial_code', '', '', '', 'pk');
  $this->push_element('company_name', '', '', '', '');
  $this->push_element('start_price', '', '', '', '');
  $this->push_element('end_price', '', '', '', '');
  $this->push_element('high_price', '', '', '', '');
  $this->push_element('low_price', '', '', '', '');
  $this->push_element('yield_value', '', '', '', '');

}

//private:


} // end of class

