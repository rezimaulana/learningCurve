<?php

// Complete the repeatedString function below.
function repeatedString($s, $n) {
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
return $result;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

$s = '';
fscanf($stdin, "%[^\n]", $s);

fscanf($stdin, "%ld\n", $n);

$result = repeatedString($s, $n);

fwrite($fptr, $result . "\n");

fclose($stdin);
fclose($fptr);
