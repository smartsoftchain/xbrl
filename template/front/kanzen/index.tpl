<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="ja" xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://gmpg.org/xfn/11">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="content-script-type" content="text/javascript">
<title>株式銘柄ピンポイントチェッカー</title>
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
<div class="left_con">ようこそ {$member->get_value("name")} さん</div>
<div class="right_con" align="right">最新更新日時　{$last_date}</div>

<h2>リアルタイム速報</h2>
<div class="left_con01"><input type="button" onClick="location.href='index.php?c=asukai';" value="次回の買い注目銘柄を確認する" class="button01" /></div>
<div class="right_con01"><input type="button" onClick="location.href='index.php?c=asuuri';" value="次回の売り注目銘柄を確認する" class="button01" /></div>
<p>&nbsp;</p>
<p>&nbsp;</p>

<h2>取引推奨銘柄を探す</h2>
<div class="left_con01"><input type="button" onClick="location.href='index.php?c=search_focus';" value="注目銘柄から探す" class="button01" /></div>
<div class="left_con01"><input type="button" onClick="location.href='index.php?c=search_focus2';" value="最注目銘柄から探す" class="button01" /></div>
<div align="center"><input type="button" onClick="location.href='index.php?c=search_rise';" value="急上昇銘柄を確認する" class="button01" /></div>
<p>&nbsp;</p>
<p>&nbsp;</p>

<h2>売りサイン銘柄確認</h2>
<div align="center"><input type="button" onClick="location.href='index.php?c=search_focus3';" value="過去１００日、売りサイン発生銘柄確認" class="button01" /></div>
<p>&nbsp;</p>
<p>&nbsp;</p>

<h2>ウォッチリスト（マイリスト）</h2>
<div align="center"><input type="button" onClick="location.href='index.php?c=watchlist';" value="ウォッチリスト（マイリスト）一覧" class="button01" /></div>
<p>&nbsp;</p>
<p>&nbsp;</p>

<h2>その他</h2>
<div align="center"><input type="button" onClick="location.href='index.php?c=user_info';" value="会員情報編集" class="button01" /></div>
<p>&nbsp;</p>
<div align="center"><input type="button" onClick="location.href='index.php?c=logout';" value="ログアウト" class="button01" /></div>
<p>&nbsp;</p>
<p>&nbsp;</p>
</div>


</div>
<!-- フッター上部 -->
{include file="footer.tpl"}
</body>
</html>
