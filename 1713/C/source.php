<?php

// 1713 C. Build Permutation
// _dp_, _math_, _constructive_, _indexes_, *1200

const N = 100_000;

$sq = [];

for ($i = 0; $i * $i <= 2 * N; ++$i) {
    $sq[$i2 = $i * $i] = $i2;
}

/** @var list<array> $perm */
$perm = array_fill(0, 2 * N, []);

$perm[0] = [0, 0];
$perm[1] = [1, 0];
$perm[2] = [2, 2];

$q = 0;
for ($i = 0; $i < N; ++$i) {
    $s = $q * $q;

    if (isset($sq[$i])) {
        ++$q;
    }

    $perm[$i] = [$i, $s - $i];
}

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);

    $resPerm = [];
    $i = $n - 1;

    while (~$i) {
        $p = $perm[$i];
        $resPerm[] = $p;
        $i = $p[1] - 1;
    }

    $resPerm = array_reverse($resPerm);

    $res = [];
    foreach ($resPerm as [$st, $en]) {
        $res[] = range($st, $en);
    }

    $res = array_merge(...$res);

    fprintf(STDOUT, str_repeat('%u ', count($res)).PHP_EOL, ...$res);
}
/*

3
1 0 2
0 1 2
1 1 4

4

0 3 2 1
0 1 2 3

0 4 4 4


7
1 0 2 6 5 4 3
0 1 2 3 4 5 6

1 1 4 9 9 9 9

8
1       0     7   6   5   4 3 2
0       1     2   3   4   5 6 7
9|4|1|0 9|4|1 9|4 9|4 9|4 9 9 9


11
            | 10  9   8   7   6
0 1 2 3 4 5 | 6   7   8   9   10
            | 16  16  16  16  16


        | 5  4
0 1 2 3 | 4  5
        | 9  9

0 3 2 1
0 1 2 3
0 4 4 4

0
0

1 0
0 1

1 0 2
0 1 2

0 3 2 1
0 1 2 3

4 3 2 1 0
0 1 2 3 4

0 3 2 1 5 4
0 1 2 3 4 5

1 0 2 6 5 4 3
0 1 2 3 4 5 6

1 0 7 6 5 4 3 2
0 1 2 3 4 5 6 7

0 8 7 6 5 4 3 2 1
0 1 2 3 4 5 6 7 8

9 8 7 6 5 4 3 2 1 0
0 1 2 3 4 5 6 7 8 9

0, 1, 4, 9, 16, 25, 36, 49, 64, 81
 */
