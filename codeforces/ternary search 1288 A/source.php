<?php

function _time(int $x, int $d)
{
    return $x + ceil($d / ($x + 1));
}

function ternary_search(int $n, int $d)
{
    $l = 0;
    $r = $n;

    while ($r - $l > 8) {
        $m1 = $l + ($r - $l) / 3;
        $m2 = $r - ($r - $l) / 3;

        $f1 = _time($m1, $d);
        $f2 = _time($m2, $d);

        if ($f1 > $f2) {
            $l = $m1;
        } elseif ($f1 < $f2) {
            $r = $m2;
        } else {
            $l = $m1;
            $r = $m2;
        }
    }

    $min = INF;
    $minI = -1;
    for ($i = $l; $i <= $r; ++$i) {
        $cur = _time($i, $d);

        if ($cur < $min) {
            $min = $cur;
            $minI = $i;
        }
    }

    if ($minI === -1) {
        echo "$l:$r - $d\n";
        echo _time($l, $d);
        throw new \RuntimeException('Out Of Range');
    }

    return $minI;
}

function solve(int $n, int $d): bool
{
    if ($d <= $n) {
        return true;
    }

    $opDays = ternary_search($n, $d);

    return (_time($opDays, $d) <= $n);
}

$t = (int)readline();

while ($t--) {
    if (solve(...explode(' ', readline()))) {
        echo "YES\n";
    } else {
        echo "NO\n";
    }
}

