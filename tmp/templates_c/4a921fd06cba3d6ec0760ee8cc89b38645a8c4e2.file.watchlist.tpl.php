<?php /* Smarty version Smarty-3.0.8, created on 2016-06-17 10:20:53
         compiled from "/var/www/html/xbrl/template/front/watchlist.tpl" */ ?>
<?php /*%%SmartyHeaderCode:7979236495763507571ef17-18633879%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '4a921fd06cba3d6ec0760ee8cc89b38645a8c4e2' => 
    array (
      0 => '/var/www/html/xbrl/template/front/watchlist.tpl',
      1 => 1466064867,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '7979236495763507571ef17-18633879',
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
<title>ウォッチリスト一覧|株式銘柄ピンポイントチェッカー「株PON PRO版」</title>
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
<h2>ウォッチリスト一覧</h2>

<h3>&quot;最注目&quot;銘柄一覧</h3>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="10%">証券コード</th>

    	<th width="12%">銘柄名</th>
    	<th width="13%">WL追加時株価</th>
    	<th width="12%">現在値</th>
    	<th width="14%">最注目銘柄登録日</th>
    	<th width="11%">売りサイン発生日</th>
    	<th width="12%">会社気象図</th>
    	<th width="6%">消除</th>
    </tr>
</thead>
<tbody>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('datum1')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
?>
	<tr>
    	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code=<?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
.T" target="_blank"><?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
</a></td>
    	<td><?php echo $_smarty_tpl->tpl_vars['data']->value['name'];?>
</td>
    	<td align="right">
   	    <?php echo number_format($_smarty_tpl->tpl_vars['data']->value['before']);?>
 円
        <br />
        (<?php echo $_smarty_tpl->tpl_vars['data']->value['clip_date'];?>
)
      </td>
    	<td align="right"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['now']);?>
 円<br />
    	  (<?php echo number_format($_smarty_tpl->tpl_vars['data']->value['now']-$_smarty_tpl->tpl_vars['data']->value['before']);?>
 円)</td>
    	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['rankup_date'];?>
</td>
    	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['handan'];?>
</td>
    	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==3){?><img src="img/icon01.gif" />快晴<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==2){?><img src="img/icon01.gif" />晴れ<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==0){?><img src="img/icon03.gif" />曇り<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==1){?><img src="img/icon02.gif" />雨<?php }?>
      </td>
    	<td align="center"><a href="?c=clip&mode=del&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
&scene=1&ret=watchlist"><img src="img/bin_closed.png" /></a></td>
    </tr>
<?php }} ?>
</tbody>
</table>
<p>&nbsp;</p>
<p>&nbsp;</p>
<h3>&quot;注目&quot;銘柄一覧</h3>

<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<!--
<p align="center">※注目銘柄から登録されたデータは「最終判断日」の記載は「-」になります。</p>
-->
<table class="tablesorter" id="myTable2">
<thead>
	<tr>
    	<th width="10%">証券コード</th>
    	<th width="16%">銘柄名</th>
    	<th width="14%">WL追加時株価</th>
    	<th width="13%">現在値</th>
    	<th width="15%">注目要銘柄登録日</th>
    	<th width="14%">狙い目度数</th>
    	<th width="12%">会社気象図</th>
    	<th width="6%">消除</th>
    </tr>
</thead>
<tbody>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('datum2')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
?>
	<tr>
    	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code=<?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
.T" target="_blank"><?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
</a></td>
    	<td><?php echo $_smarty_tpl->tpl_vars['data']->value['name'];?>
</td>
    	<td align="right">
   	    <?php echo number_format($_smarty_tpl->tpl_vars['data']->value['before']);?>
 円
        <br />(<?php echo $_smarty_tpl->tpl_vars['data']->value['clip_date'];?>
)
      </td>
    	<td align="right"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['now']);?>
 円<br />
    	  (<?php echo number_format($_smarty_tpl->tpl_vars['data']->value['now']-$_smarty_tpl->tpl_vars['data']->value['before']);?>
 円)</td>
    	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['rankup_date'];?>
</td>
    	<td align="center">
<?php $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;$_smarty_tpl->tpl_vars['i']->step = 1;$_smarty_tpl->tpl_vars['i']->total = (int)ceil(($_smarty_tpl->tpl_vars['i']->step > 0 ? $_smarty_tpl->tpl_vars['data']->value['result']+1 - (1) : 1-($_smarty_tpl->tpl_vars['data']->value['result'])+1)/abs($_smarty_tpl->tpl_vars['i']->step));
if ($_smarty_tpl->tpl_vars['i']->total > 0){
for ($_smarty_tpl->tpl_vars['i']->value = 1, $_smarty_tpl->tpl_vars['i']->iteration = 1;$_smarty_tpl->tpl_vars['i']->iteration <= $_smarty_tpl->tpl_vars['i']->total;$_smarty_tpl->tpl_vars['i']->value += $_smarty_tpl->tpl_vars['i']->step, $_smarty_tpl->tpl_vars['i']->iteration++){
$_smarty_tpl->tpl_vars['i']->first = $_smarty_tpl->tpl_vars['i']->iteration == 1;$_smarty_tpl->tpl_vars['i']->last = $_smarty_tpl->tpl_vars['i']->iteration == $_smarty_tpl->tpl_vars['i']->total;?>
★
<?php }} ?>
      </td>
    	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==3){?><img src="img/icon01.gif" />快晴<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==2){?><img src="img/icon01.gif" />晴れ<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==0){?><img src="img/icon03.gif" />曇り<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==1){?><img src="img/icon02.gif" />雨<?php }?>
      </td>
    	<td align="center"><a href="?c=clip&mode=del&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
&scene=1&ret=watchlist"><img src="img/bin_closed.png" /></a></td>
  </tr>
<?php }} ?>
</tbody>
</table>
<p>※狙い目度数が★★★★（星４個）揃ったら、最注目銘柄に移動します。
</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<!--
<h3>急上昇銘柄から登録された一覧</h3>
<!--
<p align="center">※注目銘柄から登録されたデータは「最終判断日」の記載は「-」になります。</p>
-->
<!--
<table class="tb01">
	<tr>
    	<th width="12%">証券コード</th>
    	<th width="16%">銘柄名</th>
    	<th width="16%">WL追加時株価</th>
    	<th width="10%">現在値</th>
    	<th width="28%">注目銘柄登録日</th>
    	<th width="12%">会社気象図</th>
    	<th width="6%">消除</th>
    </tr>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('datum3')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
?>
	<tr>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
</td>
    	<td><?php echo $_smarty_tpl->tpl_vars['data']->value['name'];?>
</td>
    	<td align="right"><?php echo $_smarty_tpl->tpl_vars['data']->value['clip_date'];?>
<br />
   	    <?php echo number_format($_smarty_tpl->tpl_vars['data']->value['before']);?>
 円</td>
    	<td align="right"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['now']);?>
 円<br />
    	  (<?php echo number_format($_smarty_tpl->tpl_vars['data']->value['now']-$_smarty_tpl->tpl_vars['data']->value['before']);?>
 円)</td>
    	<td align="center"><?php echo $_smarty_tpl->tpl_vars['data']->value['rankup_date'];?>
</td>
    	<td align="center">
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==3){?><img src="img/icon01.gif" />kaisei<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==2){?><img src="img/icon01.gif" />hare<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==0){?><img src="img/icon03.gif" />kumori<?php }?>
<?php if ($_smarty_tpl->tpl_vars['data']->value['tenki']==1){?><img src="img/icon02.gif" />ame<?php }?>
      </td>
    	<td align="center"><a href="?c=clip&mode=del&financial_code=<?php echo $_smarty_tpl->tpl_vars['data']->value['code'];?>
&scene=1&ret=watchlist"><img src="img/bin_closed.png" /></a></td>
    </tr>
<?php }} ?>
</table>
<p align="right">あああ</p>

<p>&nbsp;</p>
<p>&nbsp;</p>
-->
</div>


</div>
<!-- フッター上部 -->

<?php $_template = new Smarty_Internal_Template("footer.tpl", $_smarty_tpl->smarty, $_smarty_tpl, $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null);
 echo $_template->getRenderedTemplate(); $_template->rendered_content = null;?><?php unset($_template);?>


</body>
</html>
