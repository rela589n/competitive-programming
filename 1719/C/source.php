<?php

ini_set('opcache.enable', 1);
ini_set('opcache.enable_cli', 1);
ini_set('opcache.jit_buffer_size', '200M');
ini_set('opcache.jit', 1205);

$te = (int)readline();

for($t = 0; $t < $te; ++$t) {
    [$n, $qe] = array_map('intval',explode(' ',readline()));
    $arr = array_map('intval', explode(' ', readline()));
    $source = $arr;

    $wins = [];
    $ptr = 0;

    while ($arr[$ptr] !== $n) {
        $w = max($arr[1 + $ptr], $arr[$ptr]);
        $l = min($arr[1 + $ptr], $arr[$ptr]);

        $wins[$w] ??= [$ptr, 0];
        ++$wins[$w][1];

        $arr[1 + $ptr] = $w;
        $arr[] = $l;

        ++$ptr;
    }

    $wins[$n] ??= [0, INF];
    $wins[$n][1] = INF;

    for ($q = 0; $q < $qe; ++$q) {
        [$i, $k] = array_map('intval', explode(' ', readline()));
        --$i;
        --$k;

        $i = $source[$i];

        if (!isset($wins[$i])) {
            echo 0 . PHP_EOL;
            continue;
        }

        $wi = $wins[$i];

        if ($k < $wi[0]) {
            echo 0 . PHP_EOL;
            continue;
        }

        $ro = $k - $wi[0] + 1;

        echo min($ro, $wi[1]) . PHP_EOL;
    }
}

