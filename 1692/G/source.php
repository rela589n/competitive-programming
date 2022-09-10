<?php

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d', $t);

while ($t--) {
    fscanf($inp, '%d %d', $n, $k);

    $ar = fscanf($inp, str_repeat('%d ', $n));

    $res = 0;
    $segSt = 0;

    for ($i = 1; $i < $n; ++$i) {
        if ($ar[$i - 1] >= $ar[$i] << 1) {
            $res += max(0, $i - $segSt - $k);
            $segSt = $i;
        }
    }

    $res += max(0, $i - $segSt - $k);

    echo $res.PHP_EOL;
}

/*
1
6 2
10 9 8 7 6 5
// 4
1
3 1
10 9 8
//2

1
3 1
4 2 1
//0

1
4 1
10 10 1 2
//2
 */
