<?php

$lines = file('php://stdin');

array_shift($lines);

$n = 0;

foreach($lines as $line) {
    if (str_contains($line, '+')) {
        ++$n;
    } else {
        --$n;
    }
}

echo $n . PHP_EOL;

