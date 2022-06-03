<?php /* Smarty version Smarty-3.0.8, created on 2016-06-17 14:32:13
         compiled from "/var/www/html/xbrl/template/front/search_focus2.tpl" */ ?>
<?php /*%%SmartyHeaderCode:92089197957638b5d336486-79995841%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'f1ea9cc3551e9ae66658c89d0ef3dc3b07d9b6b2' => 
    array (
      0 => '/var/www/html/xbrl/template/front/search_focus2.tpl',
      1 => 1466064866,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '92089197957638b5d336486-79995841',
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
<title>最注目銘柄から探す|株式銘柄ピンポイントチェッカー「株PON PRO版」</title>
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
<h2>最注目銘柄から探す</h2>
<p>データ取得＆最新更新日時　<?php echo $_smarty_tpl->getVariable('date')->value;?>
</p>

<h3>“最注目”銘柄一覧（買いチャンスを迎えた銘柄）</h3>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<!--
<p>※注目銘柄に指定された銘柄が、4回連続で値下がりした場合、最注目銘柄に移動してくる。</p>
-->
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="8%">証券コード</th>
    	<th width="15%">銘柄名</th>
    	<th width="8%">最注目登録時株価</th>
    	<th width="8%"><?php echo $_smarty_tpl->getVariable('date2')->value;?>
の終値</th>
      <th width="8%">大出来高成績</th>
    	<th width="8%">増減率（％）</th>
    	<th width="10%">注目銘柄登録日</th>
    	<th width="10%">最注目銘柄登録日</th>
    	<th width="12%">会社気象図</th>
    	<th width="6%">ウオッチリスト</th>
    	<th width="7%">出来高推移確認</th>
  </tr>
</thead>
<tbody>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('most_datum')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
?>
	<tr>
  	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
.T" target="_blank"><?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
</a></td>
   	<td><?php echo $_smarty_tpl->tpl_vars['data']->value['company_name'];?>
</td>
   	<td><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['status3_price']);?>
 円</td>
   	<td align="right"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['end_price']);?>
 円</td>
    <td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['dekidaka_rate'];?>
 倍</td>
   	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['rate'];?>
 %</td>
   	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['rankup_date'];?>
</td>
   	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['record_date'];?>
</td>
    	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==3){?><img src="img/icon01.gif" />快晴<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==2){?><img src="img/icon01.gif" />晴れ<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==0){?><img src="img/icon03.gif" />曇り<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==1){?><img src="img/icon02.gif" />雨<?php }?>
      </td>  
 	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['cliped']==false){?>
<a href="?c=clip&mode=add&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
&scene=1&ret=search_focus2"><img src="img/application_add.png" /></a></td>
<?php }else{ ?>
追加済
<?php }?>
    </td>
    	<td align="center"><a href="?c=detail&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
"><img src="img/application_view_detail.png" /></a></td>
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
