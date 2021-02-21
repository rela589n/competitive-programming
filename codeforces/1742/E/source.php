<?php

// 1742 E. Scuza (Stairs)
// _prefix_sum_, _binary_search_, _math_, _upper_bound_ , *1200

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u %u', $n, $q);
    $ar = fscanf(STDIN, str_repeat('%u ', $n));
    $qr = fscanf(STDIN, $qFormat = str_repeat('%u ', $q));

    $heights =
    $maxStairs = array_fill(-1, $n, 0);

    foreach ($ar as $k => $item) {
        $heights[$k] = $heights[$k - 1] + $item;
    }

    foreach ($ar as $k => $a) {
        $maxStairs[$k] = max($maxStairs[$k - 1], $a);
    }

    $res = [];

    foreach ($qr as $q) {
        // find last item, which is less than q + 1
        // find first item which is greater than
        // upper bound algorithm

        $ptr = 0;
        $count = $n;

        while ($count > 0) {
            $half = $count >> 1;
            $midPtr = $ptr + $half;

            if ($maxStairs[$midPtr] <= $q) {
                $ptr = $midPtr + 1;
                $count -= $half + 1;
            } else {
                $count = $half;
            }
        }

        $res[] = $heights[$ptr - 1];
    }

    fprintf(STDOUT, $qFormat.PHP_EOL, ...$res);
}

/*
1
3 1
100 7 10
8
// 0

2
1 1
1
1
3 1
1 1 1
0

// 1, 0


1
5 5
1 2 1 5 1
1 2 0 5 6
// 1 4 0 10 10


1
4 1
1 2 2 3
2
// 5


1
5 1
1 2 3 4 3
3
// 6

1
3 1
3 4 1
1
// 0


1
5 6
1 2 3 4 5
3 2 0 4 5 1

// 117 117 117 117 117 0

 */
