#!/bin/env php
<?php

function gcd2(int $a, int $b)
{
    if ($a > $b) {
        $a %= $b;
    }

    return gcd2($b, $a);
}

function gcd(int... $values) {

}

function solve(int $k, int $n, int $m, int $d) {


    var_dump($k, $n, $m, $d);
}

solve(...explode(' ', readline()));


1/2 + 1/4 + 1/7 3