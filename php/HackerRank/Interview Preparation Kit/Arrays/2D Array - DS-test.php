<?php
$arr= array(
array(1,1,1,0,0,0),
array(0,1,0,0,0,0),
array(1,1,1,0,0,0),
array(0,0,2,4,4,0),
array(0,0,0,2,0,0),
array(0,0,1,2,4,0)
);

$x[]=$arr[3][1+1]+$arr[3][1+2];
print_r($x);

$arrayRows = count($arr);
for ($i=0; $i<$arrayRows-2; $i++){
	$arrayColumns = count($arr[$i]);
		for ($j=0; $j<$arrayColumns-2; $j++){
			$values[]=$arr[$i][$j] + $arr[$i][$j+1] + $arr[$i][$j+2] + $arr[$i+1][$j+1] + $arr[$i+2][$j] + $arr[$i+2][$j+1] + $arr[$i+2][$j+2];
		}
}
print_r(max($values));
/*
$arrayRows = count($arr);
for ($i=0; $i<$arrayRows; $i++){
	$arrayColumn = count($arr[$i]);
	for ($j=0; $j<$arrayColumn; $j++){
		
	}
}
print_r($x);
*/
/*
$x = array_push($arrayColumn[$i][$j] + $arrayColumn[$i][$j+1] + $arrayColumn[$i][$j+2] + $arrayColumn[$i+1][$j+1] + $arrayColumn[$i+2][$j] + $arrayColumn[$i+2][$j+1] + $arrayColumn[$i+2][$j+2]);
*/