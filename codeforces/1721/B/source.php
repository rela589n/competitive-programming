<?php

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%d %d %d %d %d', $n, $m, $sx, $sy, $d);

    $noWay = $sx - $d <= 1 && $sy - $d <= 1;
    $noWay |= $sx + $d >= $n && $sx - $d <= 1;
    $noWay |= $sy + $d >= $m && $sy - $d <= 1;
    $noWay |= $sx + $d >= $n && $sy + $d >= $m;

    if ($noWay) {
        echo "-1\n";
    } else {
        echo ($n + $m - 2).PHP_EOL;
    }
}
/*

1
11 3 5 2 1
// -1

1
11 3 5 1 1
// 12

1
11 3 5 3 1
// 12

1
11 3 10 2 1
// -1

1
11 3 10 2 0
// 12

1
3 5 2 3 1
// -1

1
10 4 2 2 1
// -1!


 */
