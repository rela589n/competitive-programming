<?php

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);
    $ar = fscanf(STDIN, str_repeat('%u ', $n));

    $maxP = 1;
    $maxL = 0;
    $maxR = 0;
    $maxIt = $ar[0];

    $dm = array_fill(0, $n, 1);
    $dmStarts = array_keys($dm);
    $latestPosition = [];

    foreach ($ar as $currentPos => $it) {
        if (!isset($latestPosition[$it])) {
            $latestPosition[$it] = $currentPos;
            continue;
        }

        $prevPos = $latestPosition[$it];
        $gap = $currentPos - $prevPos - 1;
        $powerWithGap = 1 + $dm[$prevPos] - $gap;

        if ($powerWithGap > 1) {
            $dm[$currentPos] = $powerWithGap;
            $dmStarts[$currentPos] = $dmStarts[$prevPos];
        }

        $latestPosition[$it] = $currentPos;
    }

    $maxP = max($dm);
    $pKeys = array_keys($dm, $maxP, true);
    $maxR = end($pKeys);
    $maxL = $dmStarts[$maxR];
    $maxIt = $ar[$maxL];

    fprintf(STDOUT, '%u %u %u'.PHP_EOL, $maxIt, $maxL + 1, $maxR + 1);
}
/*

We would check every number and:
- each idex will have weight

1
1
1
// 1 1 1

1
5
1 2 2 3 4
// 2 2 3

1
6
1 2 2 3 2 2
// 2 2 6

1
6
2 2 3 2 2 1
// 2 1 5

1
3
1 2 3
// 3 3 3
 */
