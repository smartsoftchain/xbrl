<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>ログイン|株式銘柄ピンポイントチェッカー</title>
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
<form action="index.php?c=password_fin" method="post">
<dl>
	<dt>メールアドレス</dt>
	<dd><input id="email" name="mail" type="text" class="input" tabindex="1" value="" /></dd>
</dl>
<p style="clear:left;">&nbsp;</p>
<div class="btnA" align="center">
  <input type="submit" value="送信" tabindex="2" class="button" />
</div>
</form>
</div>
<p>&nbsp;</p>
<p>&nbsp;</p>

</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
