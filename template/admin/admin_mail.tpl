<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>メール文面管理|株式銘柄発見くん！</title>
<meta name="author" content="">
<meta name="keyword" content="">
<meta name="description" content="">

<link rel="stylesheet" type="text/css" href="css/index.css" media="all">
</head>

<body>
<!-- ヘッダー -->
<div id="header">
{include file="admin_header.tpl"}
</div>
<!-- / ヘッダー -->

<!-- メインコンテンツ -->
<div id="container">

<div id="admin_main">
<h2>パスワードリマインダー</h2>
<h3>パスワードリマインダー文面設定</h3>
<form action="admin.php?c=mail_fin" method="post">
<input type="hidden" name="id" value="3">
<dl>
    <dt>送信者名</dt>
    <dd><input type="text" size="40" class="input" name="from_name" value="{$pr.from_name}" /></dd>
    <dt>メールアドレス</dt>
    <dd><input type="text" size="40" class="input" name="from_address" value="{$pr.from_address}" /></dd>
    <dt>タイトル</dt>
    <dd><input type="text" size="40" class="input" name="subject" value="{$pr.subject}" /></dd>
    <dt>文面</dt>
    <dd><textarea name="body">{$pr.body}</textarea></dd>
</dl>
<p style="clear:left;">&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="送信" class="button" /> </div>
</form>
<p>&nbsp;</p>

<h2>シグナル送信時のメール配信</h2>
<h3>買いシグナル発生時のメール文面設定</h3>
<form action="admin.php?c=mail_fin" method="post">
<input type="hidden" name="id" value="1">
<dl>
    <dt>送信者名</dt>
    <dd><input type="text" size="40" class="input" name="from_name" value="{$buy.from_name}" /></dd>
    <dt>メールアドレス</dt>
    <dd><input type="text" size="40" class="input" name="from_address" value="{$buy.from_address}" /></dd>
    <dt>タイトル</dt>
    <dd><input type="text" size="40" class="input" name="subject" value="{$buy.subject}" /></dd>
    <dt>文面</dt>
    <dd><textarea name="body">{$buy.body}</textarea></dd>
</dl>
<p style="clear:left;">&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="送信" class="button" /> </div>
</form>
<p>&nbsp;</p>
<h3>売りシグナル発生時のメール文面設定</h3>
<form action="admin.php?c=mail_fin" method="post">
<input type="hidden" name="id" value="2">
<dl>
    <dt>送信者名</dt>
    <dd><input type="text" size="40" class="input" name="from_name" value="{$sell.from_name}" /></dd>
    <dt>メールアドレス</dt>
    <dd><input type="text" size="40" class="input" name="from_address" value="{$sell.from_address}" /></dd>
    <dt>タイトル</dt>
    <dd><input type="text" size="40" class="input" name="subject" value="{$sell.subject}" /></dd>
    <dt>文面</dt>
    <dd><textarea name="body">{$sell.body}</textarea></dd>
</dl>
<p style="clear:left;">&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="送信" class="button" /> </div>
</form>
<p>&nbsp;</p>
<p>&nbsp;</p>


</div>

<!-- メニュー -->
{include file="admin_menu.tpl"}


<div class="clearfix"></div>    
</div>

<!-- フッター上部 -->
{include file="footer.tpl"}


</body>
</html>
