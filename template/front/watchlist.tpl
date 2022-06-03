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

{include file="header.tpl"}

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
{foreach from=$datum1 item=data}
	<tr>
    	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code={$data.code}.T" target="_blank">{$data.code}</a></td>
    	<td>{$data.name}</td>
    	<td align="right">
   	    {number_format($data.before)} 円
        <br />
        ({$data.clip_date})
      </td>
    	<td align="right">{number_format($data.now)} 円<br />
    	  ({number_format($data.now-$data.before)} 円)</td>
    	<td align="center">{$data.rankup_date}</td>
    	<td align="center">{$data.handan}</td>
    	<td align="center">
{if $data.tenki == 3}<img src="img/icon01.gif" />快晴{/if}
{if $data.tenki == 2}<img src="img/icon01.gif" />晴れ{/if}
{if $data.tenki == 0}<img src="img/icon03.gif" />曇り{/if}
{if $data.tenki == 1}<img src="img/icon02.gif" />雨{/if}
      </td>
    	<td align="center"><a href="?c=clip&mode=del&financial_code={$data.code}&scene=1&ret=watchlist"><img src="img/bin_closed.png" /></a></td>
    </tr>
{/foreach}
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
{foreach from=$datum2 item=data}
	<tr>
    	<td align="right"><a href="http://stocks.finance.yahoo.co.jp/stocks/detail/?code={$data.code}.T" target="_blank">{$data.code}</a></td>
    	<td>{$data.name}</td>
    	<td align="right">
   	    {number_format($data.before)} 円
        <br />({$data.clip_date})
      </td>
    	<td align="right">{number_format($data.now)} 円<br />
    	  ({number_format($data.now-$data.before)} 円)</td>
    	<td align="center">{$data.rankup_date}</td>
    	<td align="center">
{for $i=1 to $data.result}
★
{/for}
      </td>
    	<td align="center">
{if $data.tenki == 3}<img src="img/icon01.gif" />快晴{/if}
{if $data.tenki == 2}<img src="img/icon01.gif" />晴れ{/if}
{if $data.tenki == 0}<img src="img/icon03.gif" />曇り{/if}
{if $data.tenki == 1}<img src="img/icon02.gif" />雨{/if}
      </td>
    	<td align="center"><a href="?c=clip&mode=del&financial_code={$data.code}&scene=1&ret=watchlist"><img src="img/bin_closed.png" /></a></td>
  </tr>
{/foreach}
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
{foreach from=$datum3 item=data}
	<tr>
    	<td align="right">{$data.code}</td>
    	<td>{$data.name}</td>
    	<td align="right">{$data.clip_date}<br />
   	    {number_format($data.before)} 円</td>
    	<td align="right">{number_format($data.now)} 円<br />
    	  ({number_format($data.now-$data.before)} 円)</td>
    	<td align="center">{$data.rankup_date}</td>
    	<td align="center">
{if $data.tenki == 3}<img src="img/icon01.gif" />kaisei{/if}
{if $data.tenki == 2}<img src="img/icon01.gif" />hare{/if}
{if $data.tenki == 0}<img src="img/icon03.gif" />kumori{/if}
{if $data.tenki == 1}<img src="img/icon02.gif" />ame{/if}
      </td>
    	<td align="center"><a href="?c=clip&mode=del&financial_code={$data.code}&scene=1&ret=watchlist"><img src="img/bin_closed.png" /></a></td>
    </tr>
{/foreach}
</table>
<p align="right">あああ</p>

<p>&nbsp;</p>
<p>&nbsp;</p>
-->
</div>


</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
