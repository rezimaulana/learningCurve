<?php
/*
$c=[0,0,1,0,0,1,0];
$x = count($c);
$count = -1;

for($i=0; $i<$x; $i++)
{
	if($i+2<$x && $c[$i+2] == 0){
		$i=$i+2;
		echo $i."<br>";
	}
	else{
		$i=$i+1;
		echo $i."<br>";
	}
	$count++;
}


echo $count;
*/
$c=[0,0,1,0,0,1,0];
$x = count($c);
$count = -1;

for($i=0; $i<$x;)
{
    if($i+2<$x && $c[$i+2] == 0){
        $i=$i+2;
    }
    else{
        $i=$i+1;
    }
    $count++;
}
echo $count;
?>