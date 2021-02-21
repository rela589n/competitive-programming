<?php

// 1692 E. Binary Deque
// _impl_, _two_pointers_, _binary_array_, *1200
// Find the longest possible subarray which makes up desired sum.
//  1. Initialize sum from array prefix. The subarray is [0, K];
//  2. Shift Left pointer by one and Right pointer by necessary amount;
//  3. Check if current length greater than calculated up to moment.

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%u %u', $n, $sum);

    $ar = fscanf(STDIN, str_repeat('%u ', $n));

//    $en = [$ar[0]];
//    $enC = array_fill(0, $n, 1); // every element is at least once
//    $enL = 0;
//
//    for ($i = 1; $i < $n; ++$i) {
//        if ($ar[$i] === $en[$enL]) {
//            ++$enC[$enL];
//        } else {
//            $en[++$enL] = $ar[$i];
//        }
//    }

    $s = 0;
    for ($j = 0; $j < $n; ++$j) {
        $newS = $s + $ar[$j];

        if ($newS > $sum) {
            break;
        }

        $s = $newS;
    }

    if ($s !== $sum) {
        echo -1 .PHP_EOL;
        continue;
    }

    $l = 0;
    $r = $j - 1;
    $maxLen = $r - $l + 1;

    while (true) {
        $s -= $ar[$l++];

        for ($j = $r + 1; $j < $n; ++$j) {
            $newS = $s + $ar[$j];

            if ($newS > $sum) {
                break;
            }

            $s = $newS;
        }

        $r = $j - 1;

        if ($s !== $sum) {
            break;
        }

        $maxLen = max($maxLen, $r - $l + 1);
    }

    echo ($n - $maxLen).PHP_EOL;
}
/*

1
5 1
1 0 1 0 0
1

1
14 2
1 1 1 1 1 0 0 0 1 1 0 0 0 1
6

1
3 1
1 0 0

 */
