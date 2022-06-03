<?php
/*
 * admin用の認証テーブル 用 clump
 *
 */
require_once("clump/base/auth_admin_user_clump_base.inc");

class auth_admin_user_clump extends auth_admin_user_clump_base {


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
  $this->push_validate('id', 0, ''); // ログイン用ID込みのID
  $this->push_validate('pass', 0, ''); // パスワード。適宜salted hash＆ストレッチ
  $this->push_validate('status', 0, ''); // ステータス。基本未使用、ロール管理などに使える領域
  $this->push_validate('lock_time', 0, ''); // ここが０でない場合、エポック秒でここの時間まではログイン不可
  $this->push_validate('err_count', 0, ''); // ログインエラーの回数。一定回数でlock_timeに時間を設定する

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
