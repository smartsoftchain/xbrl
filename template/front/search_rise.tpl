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

{include file="header.tpl"}

</div>
<!-- / ヘッダー -->

<!-- メインコンテンツ -->
<div id="container">

<div id="main">
<p>データ取得＆最新更新日時　{$date}</p>

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
{foreach from=$datum item=data key=i}
	<tr>
  	<td align="center">{$i+1}</td>
  	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code={$data.code}.T" target="_blank">{$data.code}</a></td>
   	<td>{$data.name}</td>
   	<td align="right">{$data.price} 円</td>
   	<td align="right" class="style02">{($data.price-$data.bk_price)} 円<br />
   	  ({$data.rate}%)</td>
<!--
   	<td align="center">
{if $data.cliped == false}
<a href="?c=clip&mode=add&financial_code={$data.code}&scene=2&ret=search_rise"><img src="img/application_add.png" /></a></td>
{else}
追加済
{/if}
    </td>
-->
  </tr>
{/foreach}
</tbody>
</table>
<p>&nbsp;</p>
<p>&nbsp;</p>
</div>

</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
