<?php

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);
    $ar = fscanf(STDIN, $form = str_repeat('%u ', $n));
    $br = fscanf(STDIN, $form);

    $minAr = [];
    $maxAr = [];

    $bRange = [];
    $bKey = $n - 1;

    $aCount = 0;

    foreach (array_reverse($ar) as $key => $a) {
        while (~$bKey && ($bItem = $br[$bKey]) >= $a) {
            $bRange [] = $bItem;
            --$bKey;
        }

        ++$aCount;
        $minAr[] = end($bRange) - $a;
        $maxAr[] = reset($bRange) - $a;

        if ($aCount === count($bRange)) {
            $aCount = 0;
            $bRange = [];
        }
    }

    echo implode(' ', array_reverse($minAr)) . PHP_EOL;
    echo implode(' ', array_reverse($maxAr)) . PHP_EOL;

//    $minAr = [];
//
//    foreach ($ar as $a) {
//        if ($n === 1) {
//            $minAr[] = $n - 1;
//            continue;
//        }
//
//        $l = 1;
//        $r = $n; // will hold result
//
//        while ($l <= $r) {
//            $mid = ($l + $r) >> 1;
//            $v = $br[$mid];
//
//            if ($v < $a) {
//                $l = $mid + 1;
//            } elseif ($br[$mid - 1] >= $a) { // v >= a && preV >= a
//                $r = $mid - 1;
//            } else {
//                $l = $r = $mid;
//                break;
//            }
//        }
//
//        $minAr[] = $r;
//    }
//
//    $ptr = $n - 1;
//
//    $maxAr = array_keys($ar);
//
//    foreach ($minAr as $key => $index) {
//        $maxAr[$index] = $key;
//    }

//    foreach ($minAr as $key => $item) {
//        echo ($br[$item] - $ar[$key]).' ';
//    }
//
//    echo PHP_EOL;
//
//    foreach ($maxAr as $key => $item) {
//        echo ($br[$item] - $ar[$key]).' ';
//    }

//    echo PHP_EOL;
}

/*

1
1
1
2
// 1
// 1

1
4
10 11 12 30
21 23 25 31
// 11 10 9  1
// 15 14 13 1

1
4
10 20 30 40
22 33 33 55
// 12 2  3 15
// 23 13 3 15

40 30 20 10
55 33 22 33

10 20 30 40
45 2  3  -7

1
4
1 2 3 4
1 2 3 4
// 0 0 0 0
// 0 0 0 0

1
4
1 2 3 4
1 3 3 4
// 0 1 0 0
//

1
2
1 2
3 4

1
5
10 20 30 40 40
11 22 33 44 55

// 1  2  3  4   4
// 1 2 3    15  15

1
4
1 2 3 4
5 6 7 8
// 4 3 2 1
// 7 6 5 4


a = 1  2  3
b = 10 20 30

9  8  7
29 28 27

min = min(b) - max(a), first which is not negative



a = 1  2  3
b = 1  2  3


1 2 3





 */

