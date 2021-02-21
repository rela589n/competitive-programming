<?php

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d', $t);

while ($t--) {
    fscanf($inp, '%d', $n);
    $format = str_repeat('%s ', $n);

    $fi = array_flip(fscanf($inp, $format));
    $se = array_flip(fscanf($inp, $format));
    $th = array_flip(fscanf($inp, $format));

    $r1 = count(array_diff_key($fi, $se, $th)) * 3 +
        count(array_diff_key(array_intersect_key($fi, $se), $th)) +
        count(array_diff_key(array_intersect_key($fi, $th), $se));
    echo "$r1 ";

    $r2 = count(array_diff_key($se, $fi, $th)) * 3 +
        count(array_diff_key(array_intersect_key($se, $fi), $th)) +
        count(array_diff_key(array_intersect_key($se, $th), $fi));
    echo "$r2 ";

    $r3 = count(array_diff_key($th, $fi, $se)) * 3+
        count(array_diff_key(array_intersect_key($th, $fi), $se))+
        count(array_diff_key(array_intersect_key($th, $se), $fi));
    echo "$r3 ";

    echo PHP_EOL;
}
