<?php

$inp = fopen('php://stdin', 'rb');

fscanf($inp, '%d', $t);

while ($t--) {
    $ar = fscanf($inp, str_repeat('%d ', 4));

    echo count(array_filter($ar, static fn($el) => $el > $ar[0])) . PHP_EOL;
}
