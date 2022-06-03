<?php
ini_set("display_errors", "on");

// 環境依存する設定
// 基準ディレクトリの設定
$bp = '/var/www/html/xbrl/';


// 環境依存しない部分のとりこみ
require_once( $bp . 'base_environmental-non-dependent.inc');
