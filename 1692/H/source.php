<?php

$format = str_repeat('%d ', 2 * 10 ** 5);

fscanf(STDIN, '%d', $t);

$start = microtime(true);

$totalRead = 0;
$totalPrepare = 0;
$totalLoop = 0;

while ($t--) {
    fscanf(STDIN, '%d', $n);

    $beforeRead = microtime(true);
    $ar = array_filter(fscanf(STDIN, $format));
    $afterRead = microtime(true);

    $totalRead += $afterRead - $beforeRead;

    $maxP = 1;
    $maxR = 0;

    $beforePrepare = microtime(true);

    $dm = array_fill(0, $n, 1);
    $dmStarts = array_keys($dm);
    $latestPosition = array_flip(array_reverse($ar, true));

    $afterPrepare = microtime(true);
    $totalPrepare += $afterPrepare - $beforePrepare;

    $beforeLoop = microtime(true);

    foreach ($ar as $currentPos => $it) {
        $prevPos = $latestPosition[$it];
        $gap = $currentPos - $prevPos - 1;

        if (!~$gap) {
            continue;
        }

        $powerWithGap = 1 + $dm[$prevPos] - $gap;

        if ($powerWithGap > 1) {
            $dm[$currentPos] = $powerWithGap;
            $dmStarts[$currentPos] = $start = $dmStarts[$prevPos];

            if ($maxP < $powerWithGap) {
                $maxP = $powerWithGap;
                $maxR = $currentPos;
            }
        }

        $latestPosition[$it] = $currentPos;
    }

    $afterLoop = microtime(true);
    $totalLoop += $afterLoop - $beforeLoop;


    $maxL = $dmStarts[$maxR];
    $maxIt = $ar[$maxL];

    fprintf(STDOUT, '%d %d %d'.PHP_EOL, $maxIt, $maxL + 1, $maxR + 1);
//
//    if ($n === 12500 && $t === 12) {
//        var_dump($totalRead, $totalPrepare, $totalLoop);
//        die;
//    }
}
        var_dump($totalRead, $totalPrepare, $totalLoop);

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
