<?php

fscanf(STDIN, '%u', $t);
while ($t--) {
    fscanf(STDIN, '%u', $n);

    $ar = fscanf(STDIN, str_repeat('%u ', $n));

    if ($n <= 2) {
        echo 'YES'.PHP_EOL;
        continue;
    }

    // try asc

    $sorted = true;

    for ($i = 1; $i < $n; ++$i) {
        if ($ar[$i - 1] > $ar[$i]) {
            $sorted = false;
            break;
        }
    }

    if (!$sorted) {
        $sorted = true;
        for (++$i; $i < $n; ++$i) {
            if ($ar[$i - 1] < $ar[$i]) {
                $sorted = false;
                break;
            }
        }
    }

    if ($sorted) {
        echo 'YES'.PHP_EOL;
    } else {
        echo 'NO'.PHP_EOL;
    }
}

/*

1
5
1 2 3 2 1
// yes

1
5
3 2 1 2 3
// no

1
5
1 2 3 4 5
// yes

1
4
1 1 1 1
// yes

1
7
2 1 3 4 2 1 2
// no
 */
