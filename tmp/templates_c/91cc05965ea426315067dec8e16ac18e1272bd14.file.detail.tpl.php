<?php /* Smarty version Smarty-3.0.8, created on 2016-06-17 15:23:54
         compiled from "/var/www/html/xbrl/template/front/detail.tpl" */ ?>
<?php /*%%SmartyHeaderCode:5989328655763977aa143d9-00338617%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '91cc05965ea426315067dec8e16ac18e1272bd14' => 
    array (
      0 => '/var/www/html/xbrl/template/front/detail.tpl',
      1 => 1466064864,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '5989328655763977aa143d9-00338617',
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
<title>出来高数確認|株式銘柄ピンポイントチェッカー「株PON PRO版」</title>
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
<p>最新更新日時　<?php echo $_smarty_tpl->getVariable('date')->value;?>
</p>
<h2>出来高数確認</h2>
<p>※直近２１日間の出来高数を記載しています。</p>
<p>証券コード：<a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code=<?php echo $_smarty_tpl->getVariable('code')->value;?>
.T" target="_blank"><?php echo $_smarty_tpl->getVariable('code')->value;?>
</a>　銘柄名：　<?php echo $_smarty_tpl->getVariable('name')->value;?>
</p>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<p>&nbsp;</p>
<!--
<p align="right">※出来高倍率は、当日の出来高を前日の20日移動平均で割った数値です<br>
※株価推移は、当日の終値と前日の終値を比較した結果を表しています
。
--></p>
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="15%">日付</th>
    	<th width="20%">終値</th>
    	<th width="18%">出来高</th>
    	<th width="18%">出来高(20日平均)</th>
    	<th width="15%">出来高倍率</th>
    	<th width="14%">株価推移</th>
  </tr>
</thead>
<?php $_smarty_tpl->tpl_vars['bk_end'] = new Smarty_variable(0, null, null);?>
<?php $_smarty_tpl->tpl_vars['bk_value'] = new Smarty_variable(0, null, null);?>
<tbody>
<?php  $_smarty_tpl->tpl_vars['data'] = new Smarty_Variable;
 $_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;
 $_from = $_smarty_tpl->getVariable('datum')->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
if ($_smarty_tpl->_count($_from) > 0){
    foreach ($_from as $_smarty_tpl->tpl_vars['data']->key => $_smarty_tpl->tpl_vars['data']->value){
 $_smarty_tpl->tpl_vars['i']->value = $_smarty_tpl->tpl_vars['data']->key;
?>
	<tr>
    	<td class="<?php if (count($_smarty_tpl->getVariable('datum')->value)==$_smarty_tpl->tpl_vars['i']->value+1){?>impact01<?php }?>"><?php echo str_replace("-","/",$_smarty_tpl->tpl_vars['data']->value['trade_date']);?>
</td>
    	<td align="right" class="<?php if (count($_smarty_tpl->getVariable('datum')->value)==$_smarty_tpl->tpl_vars['i']->value+1){?>impact01<?php }?>"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['end_price']);?>
 円<br />
<?php if ($_smarty_tpl->tpl_vars['i']->value!=0){?>
前日比：(<?php echo $_smarty_tpl->tpl_vars['data']->value['end_price']-$_smarty_tpl->getVariable('bk_end')->value;?>
 円)
<?php }else{ ?>
(+- 0 円)
<?php }?>
      </td>
    	<td align="right" class="<?php if (count($_smarty_tpl->getVariable('datum')->value)==$_smarty_tpl->tpl_vars['i']->value+1){?>impact01<?php }?>"><?php echo number_format($_smarty_tpl->tpl_vars['data']->value['yield_value']*1000);?>
 株</td>

<td align="center" class="<?php if (count($_smarty_tpl->getVariable('datum')->value)==$_smarty_tpl->tpl_vars['i']->value+1){?>impact01<?php }?>">
<?php echo number_format($_smarty_tpl->tpl_vars['data']->value['20_days_average']);?>
 株
</td>
      </td>
<td align="center" class="<?php if (count($_smarty_tpl->getVariable('datum')->value)==$_smarty_tpl->tpl_vars['i']->value+1){?>impact01<?php }?>">
<?php if ($_smarty_tpl->tpl_vars['i']->value!=0){?>
  <?php if ($_smarty_tpl->tpl_vars['data']->value['20_days_average']==0){?>
    測定不能
  <?php }else{ ?>
    <?php echo round($_smarty_tpl->tpl_vars['data']->value['yield_value']/$_smarty_tpl->tpl_vars['data']->value['20_days_average']*1000,1);?>
 倍
  <?php }?>
<?php }else{ ?>
----
<?php }?>
      </td>

    	<td align="center" class="<?php if (count($_smarty_tpl->getVariable('datum')->value)==$_smarty_tpl->tpl_vars['i']->value+1){?>impact01<?php }?>">
<?php if ($_smarty_tpl->tpl_vars['i']->value!=0){?>
  <?php if (0<($_smarty_tpl->tpl_vars['data']->value['end_price']-$_smarty_tpl->getVariable('bk_end')->value)){?>
    <font color="#0000FF"><b>上昇</b></font>
  <?php }elseif(0==($_smarty_tpl->tpl_vars['data']->value['end_price']-$_smarty_tpl->getVariable('bk_end')->value)){?>
    <b>変動なし</b>
  <?php }else{ ?>
    <font color="#A52A2A"><b>下落</b></font>
  <?php }?>
<?php }else{ ?>
  <b>NODATA</b>
<?php }?>
      </td>
  </tr>
<?php $_smarty_tpl->tpl_vars['bk_end'] = new Smarty_variable($_smarty_tpl->tpl_vars['data']->value['end_price'], null, null);?>
<?php $_smarty_tpl->tpl_vars['bk_value'] = new Smarty_variable($_smarty_tpl->tpl_vars['data']->value['yield_value'], null, null);?>
<?php }} ?>
</tbody>
</table>

<p>&nbsp;</p>
</div>


</div>
<!-- フッター上部 -->

<?php $_template = new Smarty_Internal_Template("footer.tpl", $_smarty_tpl->smarty, $_smarty_tpl, $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null);
 echo $_template->getRenderedTemplate(); $_template->rendered_content = null;?><?php unset($_template);?>


</body>
</html>
