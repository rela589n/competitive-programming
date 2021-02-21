<?php

// 1692 B. All Distinct
// _greedy_, _sorting_, *800

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d', $t);

while ($t--) {
    fscanf($inp, '%d', $n);
    $ar = fscanf($inp, str_repeat('%d ', $n));

    $rc = count(array_flip($ar));

    if (($rc & 1) === ($n & 1)) {
        echo $rc.PHP_EOL;
    } else {
        echo ($rc - 1).PHP_EOL;
    }
}
/*

1
4
1 1 2 2
2

4
1 1 1 2
2

3
1 1 1
1

2
1 2
2

5
1 2 2 4 5
3
 */
