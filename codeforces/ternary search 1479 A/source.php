<?php

$n = (int)readline();

if (1 === $n) {
    echo "! 1\n";
    exit(0);
}

$cache = [];

$cache[0] = PHP_INT_MAX / 2 - 2;
$cache[$n + 1] = PHP_INT_MAX / 2 - 1;

function item(int $idx): int
{
    global $cache;

    return $cache[$idx]
        ?? ($cache[$idx] = fetch($idx));
}

function fetch(int $idx): int
{
    print "? $idx\n";

    return (int)readline();
}

$l = 1;
$r = $n;

while ($l < $r) {
    $mid = ($l + $r) >> 1;

    if (item($mid) > item($mid + 1)) {
        $l = $mid + 1;
    } elseif (item($mid) <= item($mid + 1)) {
        $r = $mid;
    }
}

print "! $l\n";
exit(0);
