<?php

// 1729 C. Jumping on Tiles
// _strings_, _constructive_, *1100

$al = array_flip(range('a', 'z'));

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%s', $s);
    $sar = str_split($s);
    $n = count($sar);

    $start = $sar[0];
    $end = $sar[$n - 1];

    if ($start <= $end) {
        asort($sar);
    } else {
        arsort($sar);
    }

    $res = [];
    foreach ($sar as $key => $item) {
        if (($start <= $end && $item < $start) || ($end <= $start && $item > $start)) {
            continue;
        }

        if (($start <= $end && $item > $end) || ($end <= $start && $item < $end)) {
            break;
        }

        $res[] = $key + 1;
    }

    fprintf(STDOUT, '%u %u'.PHP_EOL, abs($al[$end] - $al[$start]), count($res));
    fprintf(STDOUT, '%s'.PHP_EOL, implode(' ', $res));
}
/*

1
aaaaaaaa
0

1
ab


1
logac
// 9 3
// 1 3 5


a b c d e f g h i j k l m n o p q r s t u v w x y z

codeforces
c o d e f o r c e s
1 2 3 4 5 6 7 8 9 10

c c d e e f o o r s // until the last last letter reached
1 8 3 4 9 5 2 6 7 10


logic
1 4 3 5


logac
1 3 5

 */
