<?php

$t = (int)readline();

while ($t--) {
    [$n, $m] = array_map('intval', explode(' ', readline()));

    $mx = [];

    for ($i = 0; $i < $n; ++$i) {
        $mx[$i] = array_map(static fn($chr) => (int)$chr, str_split(readline()));
    }

    $totalOnes = array_sum(array_map('array_sum', $mx));

    $maxZerosSum = 0;

    for ($i = 0; $i < $n - 1; ++$i) {
        for ($j = 0; $j < $m - 1; ++$j) {
            $maxZerosSum = max(
                $maxZerosSum,
                !$mx[$i][$j] + !$mx[$i][$j + 1] + !$mx[$i + 1][$j] + !$mx[$i + 1][$j + 1],
            );
        }
    }

    if ($maxZerosSum === 0) {
        $sub = 2;
    }

    if ($maxZerosSum === 1) {
        $sub = 1;
    }

    if ($maxZerosSum >= 2) {
        $sub = 0;
    }

    echo ($totalOnes - $sub).PHP_EOL;
}
