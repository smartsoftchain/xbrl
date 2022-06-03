<?php /* Smarty version Smarty-3.0.8, created on 2016-07-02 13:16:20
         compiled from "/var/www/html/xbrl/template/front/user_info.tpl" */ ?>
<?php /*%%SmartyHeaderCode:163318034257774014f37d42-65163798%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'fa76e2c0ff55847be7e8b86c72f58e79170eb59d' => 
    array (
      0 => '/var/www/html/xbrl/template/front/user_info.tpl',
      1 => 1466064866,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '163318034257774014f37d42-65163798',
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
<title>新規会員登録</title>
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
<h2>会員情報変更</h2>
<form action="?c=user_info_fin" method="post">
<input type="hidden" name="id" value="<?php echo $_smarty_tpl->getVariable('user')->value->get_value("id");?>
">
<dl>
    <dt>名前</dt>
    <dd><input type="text" size="40" class="input" name="name" value="<?php echo $_smarty_tpl->getVariable('user')->value->get_value("name");?>
" /></dd>
    <dt>メールアドレス</dt>
    <dd><input type="text" size="40" class="input" name="mail" value="<?php echo $_smarty_tpl->getVariable('user')->value->get_value("mail");?>
" /></dd>
    <dt>パスワード</dt>
    <dd><input type="text" size="40" class="input" name="pass" value="<?php echo $_smarty_tpl->getVariable('user')->value->get_value("pass");?>
" /></dd>
</dl>
<p>&nbsp;</p>
<div class="btnA" align="center"><input type="submit" value="変更" class="button" /> </div>
</form>
<p>&nbsp;</p>
<p>&nbsp;</p>
</div>

</div>
<!-- フッター上部 -->

<?php $_template = new Smarty_Internal_Template("footer.tpl", $_smarty_tpl->smarty, $_smarty_tpl, $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null);
 echo $_template->getRenderedTemplate(); $_template->rendered_content = null;?><?php unset($_template);?>


</body>
</html>
