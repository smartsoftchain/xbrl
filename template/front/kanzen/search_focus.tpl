<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>注目銘柄から探す|株式銘柄ピンポイントチェッカー</title>
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
<h2>注目銘柄から探す</h2>
<p>データ取得＆最新更新日時　{$date}</p>

<h3>“注目”銘柄一覧</h3>
<!--
<p>※出来高が前日までの移動平均線20日の値より、「5倍」以上の増加率があった場合に注目銘柄登録される</p>
-->
<table class="tablesorter" id="myTable1">
<thead>
	<tr>
    	<th width="7%">証券<br>コード</th>
<!--
    	<th width="15%">銘柄名</th>
-->
    	<th width="10%">現在価格</th>
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
{foreach from=$more_datum item=data}
	<tr>
    	<td>{$data.financial_code}</td>
<!--
    	<td>{$data.company_name}</td>
-->
    	<td align="right">{number_format($data.end_price)} 円</td>
<!--
    	<td align="center">{$data.rate} 倍</td>
-->
    	<td align="right">{$data.dekidaka_rate} 倍</td>
    	<td align="right">{$data.record_date}</td>
    	<td align="center">
{for $i=1 to $data.rank}
★
{/for}
      </td>
    	<td align="center">
{if $data.cliped == false}
<a href="?c=clip&mode=add&financial_code={$data.financial_code}&scene=1&ret=search_focus"><img src="img/application_add.png" /></a></td>
{else}
追加済
{/if}
      </td>
    	<td align="center"><a href="?c=detail&financial_code={$data.financial_code}"><img src="img/application_view_detail.png" /></a></td>
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
