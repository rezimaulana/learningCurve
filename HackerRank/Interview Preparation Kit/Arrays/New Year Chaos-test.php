<?php

$q=array(2,1,5,3,4);
$swapCount=0;
$aCount= count($q);
for ($i=$aCount-1; $i > 0; $i--) {
	if ($q[$i] != $i +1) {
		if ((($i - 1) >= 0) && $q[$i - 1]==($i + 1)){
		$swapCount++;
		[$q[$i], $q[$i-1]] = [$q[$i-1], $q[$i]];
		}
		elseif ((($i - 2) >= 0) && $q[$i - 2] == ($i + 1)){
		$swapCount+=2;
		[$q[$i-2], $q[$i-1]] = [$q[$i-1], $q[$i-2]];
		[$q[$i-1], $q[$i]] = [$q[$i], $q[$i-1]];
		}
		else{
			echo "Too chaotic";
		}
	}
}
echo $swapCount;

/*
	if ($q[$i] != $i +1) {
		if ((($i - 1) >= 0) && $q[$i - 1]==($i + 1)){
		$swapCount++;
		[$q[$i], $q[$i-1]] = [$q[$i-1], $q[$i]];
		}
		elseif ((($i - 2) >= 0) && $q($i - 2) == ($i + 1)){
		$swapCount+=2;
		[$q[$i-2], $q[$i-1]] = [$q[$i-1], $q[$i-2]];
		[$q[$i-1], $q[$i]] = [$q[$i], $q[$i-1]];
		}
		else{
			echo "Too chaotic";
		}
	}
*/