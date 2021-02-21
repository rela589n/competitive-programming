<?php

// 1742 D. Coprime
// _greedy_, _numbers_, _brute_, *1100
// 18m

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);
    $ar = fscanf(STDIN, str_repeat('%u ', $n));

    $ar = array_flip(array_flip($ar));
    krsort($ar);

    $res = -3;

    foreach ($ar as $i => $v) {
        foreach ($ar as $j => $v2) {
            if ($j > $i) {
                continue;
            }

            if (1 === gcd($v, $v2)) {
                $res = max($res, $i + $j);
            }
        }
    }

    echo ($res + 2).PHP_EOL;
}

function gcd($a, $b)
{
    while ($a && $b) {
        if ($a > $b) {
            $a %= $b;
        } else {
            $b %= $a;
        }
    }

    return $a + $b;
}
/*

1
4
10 11 11 10

1
5
1 2 2 3 6
 */
