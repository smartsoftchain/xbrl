<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>会員情報編集</title>
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
<h2>会員情報変更</h2>
<form action="admin.php?c=member_fin" method="post">
<input type="hidden" name="id" value="{$user->get_value("id")}">
<dl>
    <dt>名前</dt>
    <dd><input type="text" size="40" class="input" name="name" value="{$user->get_value("name")}" /></dd>
    <dt>メールアドレス</dt>
    <dd><input type="text" size="40" class="input" name="mail" value="{$user->get_value("mail")}" /></dd>
    <dt>パスワード</dt>
    <dd><input type="text" size="40" class="input" name="pass" value="{$user->get_value("pass")}" /></dd>
    <dt>利用許可</dt>
    <dd>
      <input type="radio" name="status" value="0" {if $user->get_value("status") == 0}checked{/if}>利用可能
      <br>
      <input type="radio" name="status" value="1" {if $user->get_value("status") == 1}checked{/if}>利用不可
    </dd>
</dl>
<p>&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="変更" class="button" /> </div>
</form>
<p>&nbsp;</p>
<p>&nbsp;</p>
</div>

{include file="admin_menu.tpl"}
<div class="clearfix"></div>    
</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
