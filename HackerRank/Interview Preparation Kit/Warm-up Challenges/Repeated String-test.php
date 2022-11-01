<?php
/*
$s="abc";
$n=10;
$char=0;
$count=0;
$repeat;
$a;
	$a = str_repeat($s,$n);
	$b = substr($a,0,$n);
	$c = substr_count($b,'a');
	echo $c;
*/
$result=0;
$s="aba";
$n=10;
$a = substr_count($s,'a');
$b = strlen($s);
$c = $n / $b;
$d = $n % $b;
$x;

if($d == 0){
	$result = $c*$a;
}
else{
	$x = substr($s,0,$d);
	$e = ($n-$d)/$b;
	$result = ($e*$a) + substr_count($x,'a');
}
echo $result;

?>