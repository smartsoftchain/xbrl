<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>銘柄登録編集|ピンポイントチェッカー「株ＰＯＮ」</title>
<meta name="author" content="">
<meta name="keyword" content="">
<meta name="description" content="">

<link rel="stylesheet" type="text/css" href="css/index.css" media="all">
</head>

<body>
<!-- ヘッダー -->
<div id="header">
{include file="admin_header.tpl"}
</div>
<!-- / ヘッダー -->

<!-- メインコンテンツ -->
<div id="container">

<div id="admin_main">
<h2>銘柄登録編集</h2>
<form action="admin.php?c=meigara_fin" method="post" enctype="multipart/form-data">
<input type="hidden" name="type" value="csv">
※<input type="file" name="csv"> <input type="submit" value="upload"><br>
※CSVファイルをアップロードしてください。<br>
(ex)1,9445,フォーバルテレコム ,1<br>
[1 東証1部,2 東証2部, 0 マザーズ], 証券コード, 名称, [0 削除, 1 追加]
</form>
<table class="tb01">
	<tr>
    	<th width="20%">証券コード</th>
    	<th width="20%">区分</th>
    	<th width="20%">銘柄名</th>
    	<th width="20%">登録日</th>
      <th width="20%">操作</th>
    </tr>
  <tr>
<form action="admin.php?c=meigara_fin" method="post">
    <input type="hidden" name="type" value="data">
    <input type="hidden" name="mode" value="add">
    <td><input type="text" name="financial_code">
    <td>
      <select name="market_flg">
        <option value="1">東証１部</option>
        <option value="2">東証２部</option>
        <option value="0">マザーズ</option>
      </select>
    <td><input type="text" name="name">
    <td>
    <td><input type="submit" value="追加">
</form>
  </tr>
{foreach from=$datum item=data}
	<tr>
    	<td align="center">{$data.financial_code}</td>
    	<td>
        {if 1 == $data.market_flg}東証１部{/if}
        {if 2 == $data.market_flg}東証２部{/if}
        {if 0 == $data.market_flg}マザーズ{/if}
      </td>
    	<td >{$data.name}</td>
    	<td nowrap>{$data.created_at}</td>
    	<td align="center">
        <a href="javascript:void(0)" onclick="javascript:if(confirm('この銘柄の情報を削除しますか？\n銘柄が非表示になるわけではありません')){ location.href='admin.php?c=meigara_fin&financial_code={$data.financial_code}&mode=del&type=data'; } return false;"><img src="img/bin_closed.png" /></a>
      </td>
    </tr>
{/foreach}
</table>

</div>

<!-- メニュー -->
{include file="admin_menu.tpl"}

</div>

<!-- フッター上部 -->
{include file="footer.tpl"}

</body>
</html>
