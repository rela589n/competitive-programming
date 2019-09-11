<?php

$n = (int)readline();

$t = [];
$dp = [];

for ($i = 0; $i < $n; ++$i) {
    $t[] = array_map(static fn($el) => (int)$el, str_split(readline()));
}

$dp[0][0] = $t[0][0];

for ($i = 1; $i < $n; ++$i) {
    $dp[$i][0] = $dp[$i - 1][0] + $t[$i][0];
}

for ($j = 1; $j < $n; ++$j) {
    $dp[0][$j] = $dp[0][$j - 1] + $t[0][$j];
}

for ($i = 1; $i < $n; ++$i) {
    for ($j = 1; $j < $n; ++$j) {
        $dp[$i][$j] = min($dp[$i][$j - 1], $dp[$i - 1][$j]) + $t[$i][$j];
    }
}

$r = [];
for ($i = 0; $i < $n; ++$i) {
    for ($j = 0; $j < $n; ++$j) {
        $r[$i][$j] = '.';
    }
}

$i = $n - 1;
$j = $n - 1;

while ($i > 0 && $j > 0) {
    $r[$i][$j] = '#';

    if ($dp[$i][$j - 1] <= $dp[$i - 1][$j]) {
        --$j;
    } else {
        --$i;
    }

}

for ($k = $i; $k >= 0; --$k) {
    $r[$k][0] = '#';
}

for ($m = $j; $m >= 0; --$m) {
    $r[0][$m] = '#';
}

print implode("\r\n", array_map(static fn($a) => implode('',$a),$r));

