<?php

// Complete the rotLeft function below.
function rotLeft($a, $d) {
$n=count($a);
for ($oldIndex = 0; $oldIndex<$n; $oldIndex++){
    $newIndex = ($oldIndex + $n - $d) % $n;
    $rotArray[$newIndex]= $a[$oldIndex];
}
ksort($rotArray);
return $rotArray;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%[^\n]", $nd_temp);
$nd = explode(' ', $nd_temp);

$n = intval($nd[0]);

$d = intval($nd[1]);

fscanf($stdin, "%[^\n]", $a_temp);

$a = array_map('intval', preg_split('/ /', $a_temp, -1, PREG_SPLIT_NO_EMPTY));

$result = rotLeft($a, $d);

fwrite($fptr, implode(" ", $result) . "\n");

fclose($stdin);
fclose($fptr);
