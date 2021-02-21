<?php

// not solved yet!


/*
XOR | A | B
----|---|---
0   | 0 | 0
1   | 0 | 1
1   | 1 | 0
0   | 1 | 1

A - arr1
B - arr2
Max from A, Min from B

1
3
1 1 1
0 0 3
// 0

01 01 01
00 00 11
--------
01 01 10 &=> 00


1
8
0 1 2 3 4 5 6 7
7 6 5 4 3 2 1 0
// 7

000 001 010 011 100 101 110 111
111 110 101 100 011 010 001 000
-------------------------------
111 111 111 111 111 111 111 111 &=> 111


8
28 14 12 27 10 8 27 27
5 23 17 2 21 19 6 22
// 12?

 */
var_dump();

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);
    $ar = fscanf(STDIN, $form = str_repeat('%u ', $n));
    $br = fscanf(STDIN, $form);

    sort($ar);
    rsort($br);

    $and = PHP_INT_MAX;
    for ($a = reset($ar), $b = reset($br); $a !== false && $b !== false; $a = next($ar), $b = next($br)) {
        $and &= $a ^ $b;
    }

    echo $and.PHP_EOL;
}
