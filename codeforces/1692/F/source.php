<?php

// 1692 F. 3SUM
// _math_, _brute_, *1300

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%d', $n);
    $ar = fscanf(STDIN, str_repeat('%d ', $n));

    $cts = [];

    foreach ($ar as $el) {
        if (!isset($cts[$el % 10])) {
            $cts[$el % 10] = 1;
        } else {
            ++$cts[$el % 10];
        }
    }

    $simplified = [];

    foreach ($cts as $item => $count) {
        $count = min($count, 3);

        while ($count--) {
            $simplified[] = $item;
        }
    }

    $y = false;

    for ($i = 0, $iM = count($simplified); $i < $iM; ++$i) {
        for ($j = $i + 1; $j < $iM; ++$j) {
            for ($k = $j + 1; $k < $iM; ++$k) {
                if (($simplified[$i] + $simplified[$j] + $simplified[$k]) % 10 === 3) {
                    fprintf(STDOUT, "%s\n", 'YES');
                    $y = true;
                    break 3;
                }
            }
        }
    }

    if (!$y) {
        fprintf(STDOUT, "%s\n", 'NO');
    }
}
/*

1
3
1 1 1

1
5
1 1 1 3 3

1
3
13 0 0

1
3
5 5 3


 */
