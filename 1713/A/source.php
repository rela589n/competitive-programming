<?php

// 1713 A. Traveling Salesman Problem
// _impl_, _geometry_, _cartesian_, *800

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);

    $minX = 0;
    $maxX = 0;
    $minY = 0;
    $maxY = 0;

    for ($i = 0; $i < $n; ++$i) {
        fscanf(STDIN, '%d %d', $x, $y);

        $minX = min($minX, $x);
        $maxX = max($maxX, $x);
        $minY = min($minY, $y);
        $maxY = max($maxY, $y);
    }

    $res = 2 * ($maxX + $maxY - $minX - $minY);

    echo $res.PHP_EOL;
}
