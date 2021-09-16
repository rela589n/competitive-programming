<?php


[$line] = file('php://stdin');
[$n, $k] = sscanf($line,'%d %d');

$r = 4 * 60;
$e = 0;
$p = 0;


while ($e + ($p + 1) * 5 + $k <= $r) {
    ++$p;
    $e += $p * 5;
}

echo min($n,$p) . PHP_EOL;


