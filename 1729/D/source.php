<?php

// 1729 D. Friends and the Restaurant
// _greedy_, _sorting_, _two_pointers_, *1200

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);
    $x = fscanf(STDIN, $f = str_repeat('%u ', $n));
    $y = fscanf(STDIN, $f);
    $d = array_fill(0, $n, 0);

    foreach ($y as $k => $possesses) {
        $d[$k] = $possesses - $x[$k];
    }

    array_multisort($d, SORT_DESC, $x, $y);

    $g = 0;
    for ($l = 0, $r = $n - 1; $l < $r; ++$l, --$r) {
        $lv = $d[$l];
        $rv = $d[$r];
        $sum = $lv + $rv;

        while ($sum < 0 && $r - 1 > $l) {
            $rv = $d[--$r];
            $sum = $lv + $rv;
        }

        if ($sum < 0) {
            break;
        }

        ++$g;
    }

    fprintf(STDOUT, '%u'.PHP_EOL, $g);
}

/*

1
5
5 4 3 2 1
1 2 3 4 4
// 2

1
4
5 4 3 2
1 2 3 4
// 1


6
6
8 3 9 2 4 5
5 3 1 4 5 10
4
1 2 3 4
1 1 2 2
3
2 3 7
1 3 10
6
2 3 6 9 5 7
3 2 7 10 6 10
6
5 4 2 1 8 100
1 1 1 1 1 200
6
1 4 1 2 4 2
1 3 3 2 3 4
// 2 0 1 3 1 3

 */

//$ar1 = array(10, 100, 100, 0);
//$ar2 = array(1, 3, 2, 4);
//$ar3 = array(3, 2, 1, 0);
//array_multisort($ar1, $ar2, $ar3);
//
//var_dump($ar1);
//var_dump($ar2);
//var_dump($ar3);
//die;
