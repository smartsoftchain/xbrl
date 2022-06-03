<?php /* Smarty version Smarty-3.0.8, created on 2016-06-17 09:48:48
         compiled from "/var/www/html/xbrl/template/front/search_rise.tpl" */ ?>
<?php /*%%SmartyHeaderCode:1529956365576348f0dedd21-30511532%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '8fca50ffa6b2f8c9bf53b983e24b379f6d822447' => 
    array (
      0 => '/var/www/html/xbrl/template/front/search_rise.tpl',
      1 => 1466064866,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '1529956365576348f0dedd21-30511532',
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
<title>急上昇銘柄を確認|株式銘柄ピンポイントチェッカー「株PON PRO版」</title>
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
<p>データ取得＆最新更新日時　<?php echo $_smarty_tpl->getVariable('date')->value;?>
</p>

<h2>急上昇銘柄を確認</h2>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<p></p>
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="6%">NO</th>
    	<th width="14%">証券コード</th>
    	<th width="15%">銘柄名</th>
    	<th width="13%">現在値</th>
    	<th width="17%">前日比</th>
<!--
    	<th width="15%">ウオッチリスト</th>
-->
    </tr>
</thead>
<tbody>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('datum')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
 $_smarty_tpl->tpl_vars['i']->value = $_smarty_tpl->tpl_vars['data']->key;
?>
	<tr>
  	<td align="center"><?php echo $_smarty_tpl->tpl_vars['i']->value+1;?>
</td>
  	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code=<?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
.T" target="_blank"><?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
</a></td>
   	<td><?php echo $_smarty_tpl->tpl_vars['data']->value['name'];?>
</td>
   	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['price'];?>
 円</td>
   	<td align="right" class="style02"><?php echo ($_smarty_tpl->tpl_vars['data']->value['price']-$_smarty_tpl->tpl_vars['data']->value['bk_price']);?>
 円<br />
   	  (<?php echo $_smarty_tpl->tpl_vars['data']->value['rate'];?>
%)</td>
<!--
   	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['cliped']==false){?>
<a href="?c=clip&mode=add&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
&scene=2&ret=search_rise"><img src="img/application_add.png" /></a></td>
<?php }else{ ?>
追加済
<?php }?>
    </td>
-->
  </tr>
<?php }} ?>
</tbody>
</table>
<p>&nbsp;</p>
<p>&nbsp;</p>
</div>

</div>
<!-- フッター上部 -->

<?php $_template = new Smarty_Internal_Template("footer.tpl", $_smarty_tpl->smarty, $_smarty_tpl, $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null);
 echo $_template->getRenderedTemplate(); $_template->rendered_content = null;?><?php unset($_template);?>


</body>
</html>
