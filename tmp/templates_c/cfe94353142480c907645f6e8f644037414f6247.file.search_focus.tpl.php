<?php /* Smarty version Smarty-3.0.8, created on 2016-06-17 09:48:44
         compiled from "/var/www/html/xbrl/template/front/search_focus.tpl" */ ?>
<?php /*%%SmartyHeaderCode:987270006576348ece1a9b7-99123186%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'cfe94353142480c907645f6e8f644037414f6247' => 
    array (
      0 => '/var/www/html/xbrl/template/front/search_focus.tpl',
      1 => 1466064866,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '987270006576348ece1a9b7-99123186',
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
<title>注目銘柄から探す|株式銘柄ピンポイントチェッカー「株PON PRO版」</title>
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
<h2>注目銘柄から探す</h2>
<p>データ取得＆最新更新日時　<?php echo $_smarty_tpl->getVariable('date')->value;?>
</p>

<h3>“注目”銘柄一覧</h3>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<!--
<p>※出来高が前日までの移動平均線20日の値より、「5倍」以上の増加率があった場合に注目銘柄登録される</p>
-->
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="7%">証券<br>コード</th>
    	<th width="15%">銘柄名</th>
    	<th width="10%"><?php echo $_smarty_tpl->getVariable('date2')->value;?>
の終値</th>
<!--
    	<th width="10%">出来高<br>増加率</th>
-->
    	<th width="10%">大出来高成績</th>
    	<th width="14%">注目銘柄登録日</th>
    	<th width="12%">狙い目度数</th>
    	<th width="12%">ウオッチリスト</th>
    	<th width="12%">出来高推移確認</th>
  </tr>
</thead>
<tbody>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('more_datum')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
?>
	<tr>
    	<td><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
.T" target="_blank"><?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
</a></td>
    	<td><?php echo $_smarty_tpl->tpl_vars['data']->value['company_name'];?>
</td>
    	<td align="right"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['end_price']);?>
 円</td>
<!--
    	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['rate'];?>
 倍</td>
-->
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['dekidaka_rate'];?>
 倍</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['record_date'];?>
</td>
    	<td align="center">
<?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? $_smarty_tpl->tpl_vars['data']->value['rank']+1 - (1) : 1-($_smarty_tpl->tpl_vars['data']->value['rank'])+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 1, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
★
<?php }} ?>
      </td>
    	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['cliped']==false){?>
<a href="?c=clip&mode=add&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['financial_code'];?>
&scene=1&ret=search_focus"><img src="img/application_add.png" /></a></td>
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
