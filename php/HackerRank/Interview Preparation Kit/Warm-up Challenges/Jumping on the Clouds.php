<?php

// Complete the jumpingOnClouds function below.
function jumpingOnClouds($c) {
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
return $count;

}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $n);

fscanf($stdin, "%[^\n]", $c_temp);

$c = array_map('intval', preg_split('/ /', $c_temp, -1, PREG_SPLIT_NO_EMPTY));

$result = jumpingOnClouds($c);

fwrite($fptr, $result . "\n");

fclose($stdin);
fclose($fptr);
