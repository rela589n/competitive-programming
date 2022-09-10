<?php

$t = (int)readline();

while ($t--) {
    $n = (int)readline();
    $line = str_split(readline());
    $value = 0;

    for ($i = 0; $i < $n; ++$i) {
        if ($line[$i] === 'L') {
            $value += $i;
        } else {
            $value += $n - $i - 1;
        }
    }

    $it = 0;
    for ($i = 0; ($i << 1) < $n; ++$i) {
        if ($line[$i] === 'L') {
            // change to R
            $value -= $i;
            $value += $n - $i - 1;
            echo $value . ' ';
            ++$it;
        }

        if ($line[$n - $i - 1] === 'R') {
            // change to L
            $value -= $i;
            $value += $n - $i - 1;
            echo $value . ' ';
            ++$it;
        }
    }

    while ($it < $n) {
        echo $value . ' ';
        ++$it;
    }

    echo PHP_EOL;
}
