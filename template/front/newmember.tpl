<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>新規会員登録</title>
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
<h2>新規会員登録</h2>
<form action="?c=newmember_post" method="post">
<dl>
    <dt>名前</dt>
    <dd><input type="text" size="40" class="input" name="name" /></dd>
    <dt>メールアドレス</dt>
    <dd><input type="text" size="40" class="input" name="mail" /></dd>
    <dt>パスワード</dt>
    <dd><input type="text" size="40" class="input" name="pass" /></dd>
</dl>
<p>&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="登録" class="button" /> </div>
</form>
<p>&nbsp;</p>
<p>&nbsp;</p>

</div>


</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
