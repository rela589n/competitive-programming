<?php

$a = (int)strtok(file_get_contents('php://stdin'), " \n");
$b = (int)strtok(" \n");
$c = (int)strtok(" \n");

$res = $a + $b + $c;

$res = max($res, ($a + $b) * $c);
$res = max($res, $a * ($b + $c));
$res = max($res, $a * $b * $c);

echo $res;
