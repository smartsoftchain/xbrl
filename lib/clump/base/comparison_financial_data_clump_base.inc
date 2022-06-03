<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class comparison_financial_data_clump_base extends data_clump {

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
  $this->set_table_name('comparison_financial_data');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_INT); // (bigint(20) unsigned)
  $this->push_element('financial_code', '', '', '', '', data_clump::DATATYPE_STRING); // 証券コード(varchar(32))
  $this->push_element('span', '', '', '', '', data_clump::DATATYPE_INT); // 短信期間  0:通年  1:半期  2:四半期(tinyint(1) unsigned)
  $this->push_element('judge', '', '', '', '', data_clump::DATATYPE_INT); // お天気情報 0:雨 1:曇り 2:晴れ 3:快晴(tinyint(1) unsigned)
  $this->push_element('start_date', '', '', '', '', data_clump::DATATYPE_DATE); // (date)
  $this->push_element('end_date', '', '', '', '', data_clump::DATATYPE_DATE); // (date)
  $this->push_element('comp_net_sales', '', '', '', '', data_clump::DATATYPE_INT); // 売上高(decimal(12,2))
  $this->push_element('comp_operating_income', '', '', '', '', data_clump::DATATYPE_INT); // 今期営業利益(decimal(12,2))
  $this->push_element('comp_ordinary_income', '', '', '', '', data_clump::DATATYPE_INT); // 今期経常利益(decimal(12,2))
  $this->push_element('comp_net_income', '', '', '', '', data_clump::DATATYPE_INT); // 今期純利益(decimal(12,2))
  $this->push_element('updated_at', '', '', '', '', data_clump::DATATYPE_DATE); // (datetime)


}

//private:


} // end of class



