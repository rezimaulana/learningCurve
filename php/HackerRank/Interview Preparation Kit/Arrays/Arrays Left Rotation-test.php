<?php
$a=array(1,2,3,4,5);
$d=4;

$n=count($a);
for ($oldIndex = 0; $oldIndex<$n; $oldIndex++){
	$newIndex = ($oldIndex + $n - $d) % $n;
	$rotArray[$newIndex]= $a[$oldIndex];
}
ksort($rotArray);
print_r($rotArray);

