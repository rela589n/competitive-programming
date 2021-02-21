<?php

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d', $t);

while ($t--) {
    [
        $a,
        $b,
        $c,
        $d
    ] = fscanf($inp, '%d %d %d %d');

    $ad = $a * $d;
    $bc = $b * $c;

    if ($ad === $bc) {
        echo 0 .PHP_EOL;
    } elseif ($ad === 0 || $bc === 0) {
        echo 1 .PHP_EOL;
    } elseif ($ad % $bc === 0 || $bc % $ad === 0) {
        echo 1 .PHP_EOL;
    } else {
        echo 2 .PHP_EOL;
    }
}
