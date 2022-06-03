<?php
/*
 * ����ץ���
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
  $this->set_element();	// �桼����Ͽ���̤����Ǥ���Ͽ
}

/**
 * ����Ū�ʾ��������
 *
 * �ơ��֥�̾����ӥ����̾�����ꤹ��
 *
 * @access protected
 * @return boolean false�ϸ������곰��
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
