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

{include file="header.tpl"}

</div>
<!-- / ヘッダー -->

<!-- メインコンテンツ -->
<div id="container">

<div id="main">
<h2>次回市場開催時の注目銘柄</h2>
<p>※銘柄名が「--unregistered--」になっているものは、証券コードをクリックして、正しい銘柄名を御覧ください。</p>
<!--
<p>※出来高が前日までの移動平均線20日の値より、「5倍」以上の増加率があった場合に注目銘柄登録される</p>
-->
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="10%">証券コード</th>
    	<th width="15%">銘柄名</th>
    	<th width="10%">{$date2}の終値</th>
<!--
    	<th width="12%">出来高増加率</th>
-->
    	<th width="12%">大出来高成績</th>
<!--
    	<th width="12%">狙い目度数</th>
-->
    	<th width="12%">会社気象図</th>
    	<th width="12%">ウオッチリスト</th>
    	<th width="12%">出来高推移確認</th>
  </tr>
</thead>
<tbody>
{foreach from=$datum item=data}
	<tr>
    	<td><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code={$data.financial_code}.T" target="_blank">{$data.financial_code}</a></td>
    	<td>{$data.company_name}</td>
    	<td align="right">{number_format($data.end_price)}</td>
<!--
    	<td align="center">{$data.rate} 倍</td>
-->
    	<td align="center">{$data.dekidaka_rate} 倍</td>
<!--
    	<td>
{for $i=1 to $data.rank}
★
{/for}
      </td>
-->
    	<td align="center">
{if $data.tenki == 3}<img src="img/icon01.gif" />快晴{/if}
{if $data.tenki == 2}<img src="img/icon01.gif" />晴れ{/if}
{if $data.tenki == 0}<img src="img/icon03.gif" />曇り{/if}
{if $data.tenki == 1}<img src="img/icon02.gif" />雨{/if}
      </td>
    	<td align="center">
{if $data.cliped == false}
<a href="?c=clip&mode=add&financial_code={$data.financial_code}&scene=1&ret=asukai"><img src="img/application_add.png" /></a></td>
{else}
追加済
{/if}
    	<td align="center"><a href="?c=detail&financial_code={$data.financial_code}"><img src="img/application_view_detail.png" /></a></td>
    </tr>
{/foreach}
</tbody>
</table>
<!--
<p>※★が４回連続出た銘柄を１日限定で表示します</p>
-->
<p>&nbsp;</p>
<p>&nbsp;</p>
</div>

</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
