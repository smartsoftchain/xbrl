<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>拒否銘柄一覧|株式銘柄発見くん！</title>
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
<h2>拒否銘柄一覧</h2>
<table class="tb01">
	<tr>
    	<th width="20%">証券コード</th>
    	<th width="30%">名前</th>
    	<th width="20%">登録日</th>
    	<th width="20%">解除予定日</th>
      <th width="10%">操作</th>
    </tr>
  <tr>
<form action="admin.php?c=ignore_list_fin" method="post">
    <td><input type="text" name="financial_code">
    <td>
    <td><input type="text" name="created_at">
    <td><input type="text" name="reopen_at">
    <td><input type="submit" value="追加">
</form>
  </tr>
{foreach from=$datum item=data}
	<tr>
    	<td align="center">{$data.financial_code}</td>
    	<td nowrap>{$data.name}</td>
    	<td nowrap>{$data.created_at}</td>
    	<td nowrap>{$data.reopen_at}</td>
    	<td align="center">
        <a href="javascript:void(0)" onclick="javascript:if(confirm('この銘柄を拒否リストから外しますか？')){ location.href='admin.php?c=ignore_list_del&code={$data.financial_code}'; } return false;"><img src="img/bin_closed.png" /></a>
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
