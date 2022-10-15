<?php

// 1742 A. Sum
// _impl_, *800

fscanf(STDIN, '%u', $t);

while ($t--) {
    [$a, $b, $c] = fscanf(STDIN, '%d %d %d');

    if ($a + $b === $c || $a + $c === $b || $b + $c === $a) {
        echo 'YES' . PHP_EOL;
    } else {
        echo 'NO' . PHP_EOL;
    }
}
