<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>管理者情報編集|株式銘柄発見くん！</title>
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
<h2>管理者情報編集</h2>
<form action="admin.php?c=info_fin" method="post">
<dl>
    <dt>ID</dt>
    <dd><input type="text" size="40" class="input" name="id" value="{$id}" /></dd>
    <dt>ログインパスワード</dt>
    <dd><input type="text" size="40" class="input" name="pass_raw" value="{$pass_raw}" /></dd>
</dl>
<p style="clear:left;">&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="登録" class="button" /> </div>
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
