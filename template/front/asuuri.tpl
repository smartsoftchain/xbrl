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
    	<th width="11%">{$date2}の終値</th>
    	<th width="11%">想定利益（％）</th>
    	<th width="11%">最注目登録日</th>
    	<th width="16%">売りサイン発生日</th>
    	<th width="17%">出来高推移確認</th>
  </tr>
</thead>
<tbody>
{foreach from=$datum item=data}
	<tr>
    	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code={$data.financial_code}.T" target="_blank">{$data.financial_code}</a></td>
	<td>{$data.company_name}</td>
    	<td align="right">{$data.status2_price} 円</td>
    	<td align="right">{number_format($data.end_price)} 円</td>
    	<td align="right">{$data.uprate} %
    	</td>
    	<td align="right">{$data.record_date}</td>
    	<td align="center">{$data.status_3_date}</td>
<!--
    	<td align="center">
{if $data.cliped == false}
<a href="?c=clip&mode=add&financial_code={$data.financial_code}&scene=1&ret=asuuri"><img src="img/application_add.png" /></a></td>
{else}
追加済
{/if}
      </td>
-->
    	<td align="center"><a href="?c=detail&financial_code={$data.financial_code}"><img src="img/application_view_detail.png" /></a></td>
    </tr>
{/foreach}
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

{include file="footer.tpl"}


</body>
</html>
