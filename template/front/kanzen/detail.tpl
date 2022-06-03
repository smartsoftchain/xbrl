<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>出来高数確認|株式銘柄ピンポイントチェッカー</title>
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
<p>最新更新日時　{$date}</p>
<h2>出来高数確認</h2>
<p>※直近２１日間の出来高数を記載しています。</p>
<p>証券コード：{$code}　<!--銘柄名：　{$name}--></p>
<p>&nbsp;</p>
<p align="right">※出来高倍率は、当日の出来高を前日の20日移動平均で割った数値です<br>
※株価推移は、当日の終値と前日の終値を比較した結果を表しています
。</p>
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
{$bk_end=0}
{$bk_value=0}
<tbody>
{foreach from=$datum item=data key=i}
	<tr>
    	<td class="{if count($datum) == $i+1}impact01{/if}">{str_replace("-", "/", $data.trade_date)}</td>
    	<td align="right" class="{if count($datum) == $i+1}impact01{/if}">{number_format($data.end_price)} 円<br />
{if $i != 0}
({$data.end_price-$bk_end} 円)
{else}
(+- 0 円)
{/if}
      </td>
    	<td align="right" class="{if count($datum) == $i+1}impact01{/if}">{number_format($data.yield_value*1000)} 株</td>

<td align="center" class="{if count($datum) == $i+1}impact01{/if}">
{number_format($data.20_days_average)} 株
</td>
      </td>
<td align="center" class="{if count($datum) == $i+1}impact01{/if}">
{if $i != 0}
{round($data.yield_value / $data.20_days_average * 1000, 1)} 倍
{else}
----
{/if}
      </td>

    	<td align="center" class="{if count($datum) == $i+1}impact01{/if}">
{if $i != 0}
  {if 0 < ($data.end_price-$bk_end)}
    ↑
  {else if 0 == ($data.end_price-$bk_end)}
    →
  {else}
    ↓
  {/if}
{else}
  ー
{/if}
      </td>
  </tr>
{$bk_end=$data.end_price}
{$bk_value=$data.yield_value}
{/foreach}
</tbody>
</table>

<p>&nbsp;</p>
</div>


</div>
<!-- フッター上部 -->

{include file="footer.tpl"}


</body>
</html>
