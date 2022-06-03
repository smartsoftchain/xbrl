<?php
/*
 *  用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class financial_status_clump_base extends data_clump {

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
  $this->set_table_name('financial_status');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_INT); // (bigint(20) unsigned)
  $this->push_element('newest_flg', '', '', '', '', data_clump::DATATYPE_INT); // 最新を示すフラグ  0: 最新ではない, 1: 最新(tinyint(1) unsigned)
  $this->push_element('trade_date', '', '', '', '', data_clump::DATATYPE_DATE); // (date)
  $this->push_element('financial_code', '', '', '', '', data_clump::DATATYPE_STRING); // 証券コード(varchar(32))
  $this->push_element('20_days_average', '', '', '', '', data_clump::DATATYPE_FLOAT); // 前日まで20日間の出来高平均(float(13,4) unsigned)
  $this->push_element('10_days_result', '', '', '', '', data_clump::DATATYPE_INT); // 過去10日間の勝ち負け, 特大出来高移行した10日後から重要になる(当日終値が前日終値を超えていれば+1, 超えない=0, 下がっている場合 -1)(int(11))
  $this->push_element('10_days_result2', '', '', '', '', data_clump::DATATYPE_INT);
  $this->push_element('status', '', '', '', '', data_clump::DATATYPE_INT); // 0 通常, 1 大出来高(注目), 2 押し目買い(最注目), 3 特大出来高, 4 売りどき(tinyint(1) unsigned)
  $this->push_element('rank', '', '', '', '', data_clump::DATATYPE_INT); // (tinyint(1))
  $this->push_element('status_0_date', '', '', '', '', data_clump::DATATYPE_DATE); // 通常状態に入った日付, 別ステータスに移行したタイミングでnullに切り替わる(date)
  $this->push_element('status_1_date', '', '', '', '', data_clump::DATATYPE_DATE); // 大出来高になった日付, 通常状態になったタイミングでnullに切り替わる(date)
  $this->push_element('status_2_date', '', '', '', '', data_clump::DATATYPE_DATE); // 押し目買い状態に入った日付, 通常状態に入ったタイミングでnullに変わる(date)
  $this->push_element('status_3_date', '', '', '', '', data_clump::DATATYPE_DATE); // 特大出来高になった日付, 通常状態になったタイミングでnullに切り替わる(date)
  $this->push_element('status_4_date', '', '', '', '', data_clump::DATATYPE_DATE); // (date)


}

//private:


} // end of class



