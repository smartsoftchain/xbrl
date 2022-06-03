<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>会員ログイン|株式銘柄ピンポイントチェッカー</title>
<meta name="author" content="">
<meta name="keyword" content="">
<meta name="description" content="">

<link rel="stylesheet" type="text/css" href="css/index.css" media="all">
</head>

<body>
<!-- ヘッダー -->
<div id="header">

{include file="header.tpl"}

</div>
<!-- / ヘッダー -->

<!-- メインコンテンツ -->
<div id="container">

<div id="main">
<h2>会員ログイン</h2>
<form action="?c=login" method="post">
{if true == $login_error}
<font color="red">入力された内容が不正です</font>
{/if}
<dl>
    <dt>メールアドレス</dt>
    <dd><input type="text" size="40" class="input" name="id" /></dd>
    <dt>パスワード</dt>
    <dd><input type="text" size="40" class="input" name="pw" /></dd>
</dl>
<p style="clear:left;">&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="ログイン" class="button" /> </div>
</form>
<p>&nbsp;</p>
<p align="center"><a href="?c=password">パスワードを忘れた方はこちらへ</a></p>
<p align="center"><a href="?c=newmember">新規会員登録</a></p>
</div>


</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
