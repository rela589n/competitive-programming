<?php

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d', $t);

while ($t--) {
    fscanf($inp, '%d', $n);

    fscanf($inp, '%s', $a);
    fscanf($inp, '%s', $b);

    if (str_replace('G', 'B', $a) === str_replace('G', 'B', $b) ) {
        echo 'yes'.PHP_EOL;
    } else {
        echo 'no'.PHP_EOL;
    }
}
