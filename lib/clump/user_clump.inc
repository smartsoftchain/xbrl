<?php
/*
 *  用 clump
 *
 */
require_once("clump/base/user_clump_base.inc");

class user_clump extends user_clump_base {


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
  $this->push_validate('id', 0, ''); // ユーザID
  $this->push_validate('login_id', 0, ''); // ログインID
  $this->push_validate('pass', 0, ''); // パスワード
  $this->push_validate('name_k', 0, ''); // 名前（漢字）
  $this->push_validate('name_f', 0, ''); // 名前（ひらがな）
  $this->push_validate('mail', 0, ''); // メールアドレス
  $this->push_validate('adress', 0, ''); // 住所
  $this->push_validate('tel', 0, ''); // 電話番号
  $this->push_validate('age', 0, ''); // 年齢 (歳)
  $this->push_validate('purchase', 0, ''); // ローン 0:ローン、1:キャッシュ
  $this->push_validate('income', 0, ''); // 収入(万円)
  $this->push_validate('family', 0, ''); // 家族構成 (人)
  $this->push_validate('work', 0, ''); // 職業
  $this->push_validate('reliability', 0, ''); // 確度 1:A, 2:B, 3:C
  $this->push_validate('main_area', 0, ''); // 希望エリアメイン&lt;br&gt; 0:葉山町 &lt;br&gt;1:鎌倉市 &lt;br&gt;2:その他 &lt;br&gt;3:伊豆&lt;br&gt;4:秋谷・佐島
  $this->push_validate('detail_area', 0, ''); // 希望エリア詳細
  $this->push_validate('access_from', 0, ''); // 流入元 0:WEB、1:Mail、2:TEL、3:訪問、4:紹介
  $this->push_validate('invite_user_id', 0, ''); // 紹介者名
  $this->push_validate('syubetsu', 0, ''); // 物件種別　0:土地, 1:戸建, 2:マンション, 3:テラスハウス, 4:賃貸
  $this->push_validate('syubetsu_detail', 0, ''); // 物件種別詳細
  $this->push_validate('use_flag', 0, ''); // 用途 0:自宅,1:セカンドハウス,2:その他
  $this->push_validate('use_detail', 0, ''); // 用途詳細
  $this->push_validate('hope_env', 0, ''); // ご希望の環境(カンマ区切り)&lt;br&gt; 0:緑近 &lt;br&gt;1:海一望 &lt;br&gt;2:海近 &lt;br&gt;3:日当たり &lt;br&gt;4:海抜 &lt;br&gt;5:ペット可 &lt;br&gt;6:分譲他 &lt;br&gt;7:二世帯住宅 &lt;br&gt;8:SOHO &lt;br&gt;9:その他
  $this->push_validate('hope_env_free', 0, ''); // 希望環境フリー欄
  $this->push_validate('access', 0, ''); // 駅徒歩 &lt;br&gt;0:駅徒歩10分以内, &lt;br&gt;1:駅徒歩20分以内, &lt;br&gt;2:30分以内, &lt;br&gt;3:気にしない
  $this->push_validate('parking', 0, ''); // 駐車場 0:1台,&lt;br&gt;1:2台,&lt;br&gt;2:近隣賃貸でもOK,&lt;br&gt;3:不要
  $this->push_validate('land_from', 0, ''); // 土地面積下限
  $this->push_validate('land_to', 0, ''); // 土地面積上限
  $this->push_validate('rooms', 0, ''); // 間取り &lt;br&gt;0:1R・1K,&lt;br&gt;1:1LDK,&lt;br&gt;2:2LDK,&lt;br&gt;3:3LDK,&lt;br&gt;4:4LDK,&lt;br&gt;5:5LDK以上
  $this->push_validate('land_budget_from', 0, ''); // 土地予算下限(万円) 
  $this->push_validate('land_budget_to', 0, ''); // 土地予算上限(万円) 99999の場合１億円以上
  $this->push_validate('total_budget_from', 0, ''); // 総予算下限(万円) 
  $this->push_validate('total_budget_to', 0, ''); // 総予算上限(万円) 99999の場合１億円以上
  $this->push_validate('buy_limit', 0, ''); // 購入希望時期 &lt;br&gt;0:すぐにでも購入したい &lt;br&gt;1:いいものがあれば &lt;br&gt;2:1年以内 &lt;br&gt;3:2年以内
  $this->push_validate('search_start', 0, ''); // 探し始めてからどのぐらい？ &lt;br&gt;0:1か月以内,&lt;br&gt;1:3か月以内,&lt;br&gt;2:半年以内,&lt;br&gt;3:1年以内,&lt;br&gt;4:1年以上
  $this->push_validate('search_amount', 0, ''); // 探した件数 &lt;br&gt;0:0件,&lt;br&gt;1:1～5件,&lt;br&gt;2:6件～10件,&lt;br&gt;3:11件～20件,&lt;br&gt;4:20件以上
  $this->push_validate('visit_amount', 0, ''); // 不動産屋に赴いた回数 &lt;br&gt;0:0社,&lt;br&gt;1:1社,&lt;br&gt;2:2～4社,&lt;br&gt;3:5社以上
  $this->push_validate('joint_buying', 0, ''); // 共同購入について 0:興味なし,1:興味あり
  $this->push_validate('status', 0, ''); // ステータス 0:進行中,1:商談成立,2:商談不成立
  $this->push_validate('memo', 0, ''); // 備考
  $this->push_validate('regist_date', 0, ''); // 会員登録日
  $this->push_validate('update_date', 0, ''); // 更新日付
  $this->push_validate('sales', 0, ''); // 営業担当 &lt;br&gt;0:福田, &lt;br&gt;1:小川, &lt;br&gt;2:一戸, &lt;br&gt;3:遠藤, &lt;br&gt;4:内藤

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
