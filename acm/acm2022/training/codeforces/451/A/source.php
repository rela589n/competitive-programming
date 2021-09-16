<?php

[$d] = file('php://stdin');

[$n, $m] = array_map('intval',  explode(' ', $d));

$s = min($n, $m);

if ($s & 1) {
    echo "Akshat" . PHP_EOL;
} else {
    echo "Malvika" . PHP_EOL;
}
