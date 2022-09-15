<?php

// A. Two Elevators

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%u %u %u', $a, $b, $c);

    $t1 = $a - 1;
    $t2 = abs($b - $c) + $c - 1;

    if ($t1 < $t2) {
        echo "1\n";
    } elseif ($t2 < $t1) {
        echo "2\n";
    } else {
        echo "3\n";
    }
}

/*
1
1 1 1

 */
