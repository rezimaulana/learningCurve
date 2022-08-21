<?php
/*
function countingValleys($steps, $path) {
    // Write your code here
	$altitude = 0; $counter = 0;
	for ($i = 0; $i < $steps; $i++) {
		$ch = substr($path,$i);
		if ($ch == 'U') {
			$altitude++;
			if ($altitude == 0) {
				$counter++;
			}
		}
		else {
			$altitude--;
		}
	}
	return $counter;
}


$steps = 8;

$path = "UDDDUDUU";

$result = countingValleys($steps, $path);

echo $result;
*/
$steps = 8;
$path = "UDDDUDUU";
$altitude = 0; 
$counter = 0;

	for ($i = 0; $i < $steps; $i++) {
		$ch = substr($path,$i,1);
		echo $ch."-char<br>";
		if ($ch == 'U') {
			$altitude++;
			
			echo $altitude."Altitude<br>";
			echo $counter."Counter<br>";
			if ($altitude == 0) {
				$counter++;
			}
		}
		else {
			$altitude--;
			echo $altitude."Altitude<br>";
			echo $counter."Counter<br>";
		}
	}
	
echo $counter;

?>