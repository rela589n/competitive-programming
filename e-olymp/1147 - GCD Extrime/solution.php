<?php

$cached = [];

function gcd2($a, $b) {
    global $cached;
    $key = "${a}${b}";
    if (array_key_exists($key, $cached)) {
        return $cached[$key];
    }

    while ($a && $b) {
        if ($a > $b) {
            $a %= $b;
        } else {
            $b %= $a;
        }
    }

    $cached[$key] = $a + $b;

    return $a + $b;
}

$g = 0;
while (true) {
    $n = (int) readline();
    if ($n === 0) {
        break;
    }

    for ($i = 1; $i < $n; ++$i) {
        for ($j = $i + 1; $j < $n; ++$j) {
            $g += gcd2($i, $j);
        }
    }
}

echo $g;
