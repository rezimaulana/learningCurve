<?php

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

function countingValleys($steps, $path) {
    // Write your code here
    $altitude = 0; $counter = 0;
    for ($i = 0; $i < $steps; $i++) {
        $ch = substr($path,$i,1);
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

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$steps = intval(trim(fgets(STDIN)));

$path = rtrim(fgets(STDIN), "\r\n");

$result = countingValleys($steps, $path);

fwrite($fptr, $result . "\n");

fclose($fptr);
