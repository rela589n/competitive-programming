<?php

// 1729 E. Guess the Cycle Size
// _probability_, _interactive_, *1800

for ($i = 3; $i < 25 + 3; ++$i) {
    fprintf(STDOUT, '? %d %d'.PHP_EOL, 1, $i);
    fprintf(STDOUT, '? %d %d'.PHP_EOL, $i, 1);
    fflush(STDOUT);

    fscanf(STDIN, '%d', $first);

    if ($first === -1) {
        fprintf(STDOUT, '! %d' . PHP_EOL, $i - 1);
        break;
    }

    fscanf(STDIN, '%d', $second);

    if ($first !== $second) {
        fprintf(STDOUT, '! %d' . PHP_EOL, $first + $second);
        break;
    }
}
