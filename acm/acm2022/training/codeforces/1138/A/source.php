<?php

[$n, $arr] = file('php://stdin');

$n = (int) $n;

$arr = array_map('intval', explode(' ', $arr));

$mask = [$arr[0]];
$counts = [1];
$mN = 1;

for ($i = 1, $maxI = count($arr); $i < $maxI; ++$i) {
    if ($arr[$i] === $arr[$i - 1]) {
        ++$counts[$mN - 1];
    } else {
        $counts[$mN] = 1;
        $mask[$mN++] = $arr[$i];
    }
}

$res = 0;

for ($i = 1, $maxI = count($counts); $i < $maxI; ++$i) {
    $current= min($counts[$i - 1], $counts[$i]);
    $res = max($res, $current);
}

$res *= 2;


echo $res . PHP_EOL;


