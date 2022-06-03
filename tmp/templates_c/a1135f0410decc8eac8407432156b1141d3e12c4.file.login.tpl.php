<?php /* Smarty version Smarty-3.0.8, created on 2016-06-16 18:40:58
         compiled from "/var/www/html/xbrl/template/front/login.tpl" */ ?>
<?php /*%%SmartyHeaderCode:19031364025762742a6352f4-92692156%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'a1135f0410decc8eac8407432156b1141d3e12c4' => 
    array (
      0 => '/var/www/html/xbrl/template/front/login.tpl',
      1 => 1466064865,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '19031364025762742a6352f4-92692156',
  'function' => 
  array (
  ),
  'has_nocache_code' => false,
)); /*/%%SmartyHeaderCode%%*/?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>会員ログイン|株式銘柄ピンポイントチェッカー「株PON」</title>
<meta name="author" content="">
<meta name="keyword" content="">
<meta name="description" content="">

<link rel="stylesheet" type="text/css" href="css/index.css" media="all">
</head>

<body>
<!-- ヘッダー -->
<div id="header">

<?php $_template = new Smarty_Internal_Template("header.tpl", $_smarty_tpl->smarty, $_smarty_tpl, $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null);
 echo $_template->getRenderedTemplate(); $_template->rendered_content = null;?><?php unset($_template);?>

</div>
<!-- / ヘッダー -->

<!-- メインコンテンツ -->
<div id="container">

<div id="main">
<h2>会員ログイン</h2>
<form action="?c=login" method="post">
<?php if (true==$_smarty_tpl->getVariable('login_error')->value){?>
<font color="red">入力された内容が不正です</font>
<?php }?>
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

<?php $_template = new Smarty_Internal_Template("footer.tpl", $_smarty_tpl->smarty, $_smarty_tpl, $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null);
 echo $_template->getRenderedTemplate(); $_template->rendered_content = null;?><?php unset($_template);?>


</body>
</html>
