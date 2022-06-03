<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>会員一覧|株式銘柄発見くん！</title>
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
<h2>会員一覧</h2>
<table class="tb01">
	<tr>
    	<th width="5%">NO</th>
    	<th width="8%">名前</th>
    	<th width="12%">メールアドレス</th>
    	<th width="11%">パスワード</th>
    	<th width="19%">登録日</th>
        <th width="12%">ステータス</th>
        <th width="4%">修正</th>
        <th width="4%">削除</th>
    </tr>
{foreach from=$users item=user}
	<tr>
    	<td align="center">{$user->get_value("id")}</td>
    	<td nowrap>{$user->get_value("name")}</td>
    	<td>{$user->get_value("mail")}</td>
    	<td>{$user->get_value("pass")}</td>
    	<td>{str_replace("-", "/", $user->get_value("update_date"))}</td>
    	<td align="center">
{if $user->get_value("status") == 0}ログインOK{/if}
{if $user->get_value("status") == 1}ログインNG{/if}
      </td>
    	<td align="center"><a href="admin.php?c=member_edit&id={$user->get_value("id")}"><img src="img/application_edit.png" /></a></td>
    	<td align="center"><a href="#" onClick="if(confirm('削除してよろしいですか？')){ location.href='admin.php?c=member_del&id={$user->get_value("id")}'; }"><img src="img/bin_closed.png" /></a></td>
    </tr>
{/foreach}
</table>


<p>&nbsp;</p>
<p align="center">
{if $page->is_back()}<a href="admin.php?c=top&p={$now_page-1}"><span>&lt;&lt;</span></a>{/if}　
<span>
{for $i=0 to $page->get_max_page()}
  <a href="admin.php?c=top&p={$i}">{$i+1}</a>&nbsp;
{/for}
</span>
{if $page->is_next()}<a href="admin.php?c=top&p={$now_page+1}"><span>&gt;&gt;</span></a>{/if}
</p>
</div>

<!-- メニュー -->
{include file="admin_menu.tpl"}

</div>

<!-- フッター上部 -->
{include file="footer.tpl"}

</body>
</html>
