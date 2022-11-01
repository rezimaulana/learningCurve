<?php

// Complete the sockMerchant function below.
function sockMerchant($n, $ar) {
$ar = array_count_values($ar);
$count = 0;
foreach($ar as $color => $amount){
    $count += floor($amount/2);
}
return $count;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $n);

fscanf($stdin, "%[^\n]", $ar_temp);

$ar = array_map('intval', preg_split('/ /', $ar_temp, -1, PREG_SPLIT_NO_EMPTY));

$result = sockMerchant($n, $ar);

fwrite($fptr, $result . "\n");

fclose($stdin);
fclose($fptr);
