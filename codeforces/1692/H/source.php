<?php

// 1692 H. Gambling (Casino)
// _dp_, _greedy_, _math_, *1700

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%d', $n);

    $sourceArr = fscanf(STDIN, str_repeat('%d ', $n));

    $ar = [];
    foreach ($sourceArr as $key => $el) {
        // if el is power of 2, source array lookup will give us a hard time
        $ar[] = $el % 200003;
    }

    $maxP = 1;
    $maxR = 0;

    $dm = array_fill(0, $n, 1);
    $dmStarts = array_keys($dm);
    $latestPosition = array_flip(array_reverse($ar, true));

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

    $maxL = $dmStarts[$maxR];
    $maxIt = $sourceArr[$maxL];

    fprintf(STDOUT, '%d %d %d'.PHP_EOL, $maxIt, $maxL + 1, $maxR + 1);
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
