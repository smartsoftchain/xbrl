<?php
/*
 *  用 clump
 *
 */
require_once("clump/base/financial_status_clump_base.inc");

class financial_status_clump extends financial_status_clump_base {


/**
 * 基本的な情報の設定
 *
 * validate項目などを設定する。「テーブル名およびカラム名」はbase側で設定。
 *
 * @access protected
 * @return boolean falseは現状想定外。
 */
protected function set_element()
{
  //
  parent::set_element();

  /*
  typeの説明
data_clump::V_MUST     // 必須
data_clump::V_STRING   // 文字列(パラメタは文字数(バイト数)を表す
data_clump::V_NUMERIC  // 数値(パラメタは値を示す
data_clump::V_DIGIT    // 数字(パラメタは桁数を示す
data_clump::V_ALPHA    // 英字(パラメタは文字数(バイト数)を表す
data_clump::V_ALPNUM   // 英数字(パラメタは文字数(バイト数)を表す
data_clump::V_POST     // 郵便番号(nnn-nnnn、nnnnnnn、nnn nnnnの３パターンフォロー
data_clump::V_DATE     // 日付
data_clump::V_M_STRING // 全角交じりの文字列(サイズのチェックを 全角:2文字 半角:1文字として扱う
  */

  // validateの設定
  // name, type(0ならチェックしない), param(書式は'min-max')
  $this->push_validate('id', 0, ''); // 
  $this->push_validate('newest_flg', 0, ''); // 最新を示すフラグ  0: 最新ではない, 1: 最新
  $this->push_validate('trade_date', 0, ''); // 
  $this->push_validate('financial_code', 0, ''); // 証券コード
  $this->push_validate('20_days_average', 0, ''); // 前日まで20日間の出来高平均
  $this->push_validate('10_days_result', 0, ''); // 過去10日間の勝ち負け, 特大出来高移行した10日後から重要になる(当日終値が前日終値を超えていれば+1, 超えない・下がっている場合 -1)
  $this->push_validate('10_days_result2', 0, ''); 
  $this->push_validate('status', 0, ''); // 0 通常, 1 大出来高, 2 押し目買い, 3 特大出来高
  $this->push_validate('status_0_date', 0, ''); // 通常状態に入った日付, 別ステータスに移行したタイミングでnullに切り替わる
  $this->push_validate('status_1_date', 0, ''); // 大出来高になった日付, 通常状態になったタイミングでnullに切り替わる
  $this->push_validate('status_2_date', 0, ''); // 押し目買い状態に入った日付, 通常状態に入ったタイミングでnullに変わる
  $this->push_validate('status_3_date', 0, ''); // 特大出来高になった日付, 通常状態になったタイミングでnullに切り替わる
  $this->push_validate('status_4_date', 0, ''); // 特大出来高になった日付, 通常状態になったタイミングでnullに切り替わる

  // insert/updateフックの設定
  //$this->set_insert_date_name('create_date');
  //$this->set_update_date_name('update_date');

}


//private:


} // end of class


/*
割とオーバーライドしたりするのをフックしてメモ書き
メソッドの意味とかはdata_clumpを適宜調べてください。

public function is_valid_insert($conv = NULL)
{
}
public function is_valid_update($conv = NULL)
{
}

public function set_from_cgi_insert($req, $empty_overwrite_flg = false)
{
}
public function set_from_cgi_update($req, $empty_overwrite_flg = false)
{
}

public function get_all_data_to_hash($extra_param = array())
{
}

public function get_value($name)
{
}
public function set_value($name, $value, $flg = false)
{
}

*/
