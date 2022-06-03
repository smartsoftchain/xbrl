<?php /* Smarty version Smarty-3.0.8, created on 2016-06-29 13:11:34
         compiled from "/var/www/html/xbrl/template/front/asuuri.tpl" */ ?>
<?php /*%%SmartyHeaderCode:104458621557734a76a29440-17971364%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'b09a2a606be3428cf4a6f4d8b093530ab20e15c5' => 
    array (
      0 => '/var/www/html/xbrl/template/front/asuuri.tpl',
      1 => 1467171986,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '104458621557734a76a29440-17971364',
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
<title>次回の注目銘柄|株式銘柄ピンポイントチェッカー「株PON PRO版」</title>
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
<h2>次回開催市場での注目売り銘柄</h2>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<!--
<p>※過去６０日以内に売りサインが出た銘柄一覧<br /></p>
-->
<table class="tablesorter" id="myTable1"  cellspacing="1">
<thead>
	<tr>
    	<th width="8%">証券コード</th>
	<th width="15%">銘柄名</th>
    	<th width="11%" class="{ 'sorter':'procent' }">最注目登録時株価</th>
    	<th width="11%"><?php echo $_smarty_tpl->getVariable('date2')->value;?>
の終値</th>
    	<th width="11%">想定利益（％）</th>
    	<th width="11%">最注目登録日</th>
    	<th width="16%">売りサイン発生日</th>
    	<th width="17%">出来高推移確認</th>
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
    	<td align="right"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['end_price']);?>
 円</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['uprate'];?>
 %
    	</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['record_date'];?>
</td>
    	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['status_3_date'];?>
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
