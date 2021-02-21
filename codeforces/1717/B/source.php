<?php

// 1717 B. Madoka and Underground Competitions
// _constructive_, _matrix_, _mod_, *1100

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u %u %u %u', $n, $k, $r, $c);
    --$r;
    --$c;

    $mx = array_fill(0, $n, array_fill(0, $n, '.'));

    for ($i = 0; $i < $n; ++$i) {
        for ($j = (($r + $c) % $k - $i % $k + $k) % $k; $j < $n; $j += $k) {
            $mx[$i][$j] = 'X';
        }
    }

    foreach ($mx as $it) {
        fprintf(STDOUT, '%s'.PHP_EOL, implode('', $it));
    }
}
/*
1
6 3 1 1

1
6 3 1 6

All items of same diagonal have the same value of (i + j).
We need to find items where (i + j) % k === (r + c) % k

 */
