<?php

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d', $t);

while ($t--) {
    fscanf($inp, '%d', $n);

    $arr = fscanf($inp, str_repeat('%d ', $n));

    sort($arr);

    $minValues = array_slice($arr, 0, 2);
    $maxValues = array_slice($arr, -2);

    echo (array_sum($maxValues) - array_sum($minValues)).PHP_EOL;
}

fclose($inp);
