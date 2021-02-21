<?php

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%c%c', $a, $b);
    fscanf(STDIN, '%c%c', $c, $d);

    $c = count(array_unique([$a, $b, $c, $d]));

    echo ($c - 1).PHP_EOL;
}
/*

// 1 unique - 0

// 2 different - 1

rb
br

// 3 different - 2
aa
bc


// 4 all different - 3

ab
cd

bb
cd

dd
cd

dd
dd

 */
