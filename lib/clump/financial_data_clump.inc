<?php
/*
 *  用 clump
 *
 */
require_once("clump/base/financial_data_clump_base.inc");

class financial_data_clump extends financial_data_clump_base {


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
  $this->push_validate('financial_id', 0, ''); // 
  $this->push_validate('company_code', 0, ''); // 証券コード
  $this->push_validate('company_name', 0, ''); // 会社名
  $this->push_validate('start_date', 0, ''); // 決済範囲 開始日
  $this->push_validate('end_date', 0, ''); // 決済範囲 終了日
  $this->push_validate('net_sales', 0, ''); // 売上高
  $this->push_validate('operating_income', 0, ''); // 今期営業利益
  $this->push_validate('ordinary_income', 0, ''); // 今期経常利益
  $this->push_validate('net_income', 0, ''); // 今期純利益
  $this->push_validate('analysis_date', 0, ''); // 
  $this->push_validate('file_name', 0, ''); // 

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
