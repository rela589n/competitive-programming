<?php

// 1729 B. Decode String
// _strings_, _crypto_, _greedy_, *800

$al = range('a', 'z');

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%d', $n);

    $chars = fscanf(STDIN, str_repeat('%c', $n));
    foreach ($chars as &$char) {
        $char = (int)$char;
    }
    unset($char);

    $res = [];

    for ($i = 0; $i < $n; ++$i) {
        $char = $chars[$i];

        if ($char === 0) {
            if ($i + 1 < $n && $chars[$i + 1] === 0) {
                $res[] = $char;
            } else {
                $last = array_pop($res);
                $num = array_pop($res);

                $res [] = $num * 10 + $last;
            }
        } else {
            $res[] = $char;
        }
    }

    $out = [];
    foreach ($res as $it) {
        $out[] = $al[$it - 1];
    }

    echo implode('', $out).PHP_EOL;
}

/*

315045

5 4 15


9
6
315045
4
1100
7
1213121
6
120120
18
315045615018035190
7
1111110
7
1111100
5
11111
4
2606

 */
