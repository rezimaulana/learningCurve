<?php

$n = 9;
$ar = [10, 20, 20, 10, 10, 30, 50, 10, 20];

$ar = array_count_values($ar);
$count = 0;
foreach($ar as $color => $amount){
	$count += floor($amount/2);
}
echo $count;
	