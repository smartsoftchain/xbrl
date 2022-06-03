<?php /* Smarty version Smarty-3.0.8, created on 2016-06-29 14:29:52
         compiled from "/var/www/html/xbrl/template/front/search_focus3.tpl" */ ?>
<?php /*%%SmartyHeaderCode:70019840557735cd0795458-39638466%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '9dc20e77954ce390e590605a0b2eb5034e0305ea' => 
    array (
      0 => '/var/www/html/xbrl/template/front/search_focus3.tpl',
      1 => 1467178136,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '70019840557735cd0795458-39638466',
  'function' => 
  array (
  ),
  'has_nocache_code' => false,
)); /*/%%SmartyHeaderCode%%*/?>
﻿<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>過去９０日以内に売りサインが出た銘柄一覧|株式銘柄ピンポイントチェッカー「株PON PRO版」</title>
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
<h2>過去９０日以内に売りサインが出た銘柄一覧</h2>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="8%">証券コード</th>
   	<th width="11%">銘柄名</th>
    	<th width="11%">最注目登録時株価</th>
    	<th width="11%">売りサイン確定株価</th>
    	<th width="11%">想定利益（％）</th>
    	<th width="11%">最注目登録日</th>
    	<th width="10%">売りサイン発生日</th>
<!--    	<th width="12%">会社気象図</th>-->
    	<th width="15%">出来高推移確認</th>
  </tr>
</thead>
<tbody>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('datum')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
?>
	<tr>
    	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
.T" target="_blank"><?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
</a></td>
   		<td><?php echo $_smarty_tpl->tpl_vars['data']->value['company_name'];?>
</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['status2_price'];?>
 円</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['status3_price'];?>
 円</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['uprate'];?>
 %</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['record_date'];?>
</td>
    	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['uri_date'];?>
</td>
<!--
    	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['cliped']==false){?>
<a href="?c=clip&mode=add&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
&scene=1&ret=asuuri"><img src="img/application_add.png" /></a></td>
<?php }else{ ?>
追加済
<?php }?>
      </td>
-->
<!--
	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==3){?><img src="img/icon01.gif" />快晴<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==2){?><img src="img/icon01.gif" />晴れ<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==0){?><img src="img/icon03.gif" />曇り<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==1){?><img src="img/icon02.gif" />雨<?php }?>
      </td> 
--> 
    	<td align="center"><a href="?c=detail&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
"><img src="img/application_view_detail.png" /></a></td>
    </tr>
<?php }} ?>
</tbody>
</table>
<!--
<p><span class="style01">※認定日=売りシグナル発生時期になります。<br />
　基本的に、ここに表示されるのは、認定日＝売りのタイミングとなる。</span></p>
-->
<p>&nbsp;</p>
<p>&nbsp;</p>
</div>

</div>
<!-- フッター上部 -->

<?php $_template = new Smarty_Internal_Template("footer.tpl", $_smarty_tpl->smarty, $_smarty_tpl, $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null);
 echo $_template->getRenderedTemplate(); $_template->rendered_content = null;?><?php unset($_template);?>


</body>
</html>
