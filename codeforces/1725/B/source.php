<?php

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d %d', $n, $d);
++$d;
$arr = fscanf($inp, str_repeat('%d ', $n));

rsort($arr);

$res = 0;

$piv = count($arr);

for ($i = 0; $i < $piv; ++$i) {
    $l = $arr[$i];
    $p = intdiv($d, $l) + ($d % $l !== 0);

    if ($i + $p > $piv) {
        break;
    }

    $piv = $piv - $p + 1;

    ++$res;
}

echo $res.PHP_EOL;
/*

4 3
2 2 5 2

4 3
5 2 2 2
5 (2 2)


3 200
100 90 80

6 180
90 80 70 60 50 100
 */
