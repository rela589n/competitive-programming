<?php

$lines = file('php://stdin');

$n = (int)array_shift($lines);
$m = (int)array_shift($lines);

$lines = array_map('intval', $lines);
sort($lines);

$maxK = max($lines) + $m;

$resMinAr = buildResArr($lines, $m);
$minK = max($resMinAr);


echo "$minK $maxK" . PHP_EOL;


function buildResArr(array $arr, int $it) {
    // arr - sorted
    for ($i = 0, $maxI = count($arr) - 1; $i <= $maxI && $it > 0; ++$i) {
        if ($arr[$i] < $arr[$maxI]) {
            $diff = $arr[$maxI] - $arr[$i];
            $sub = min($it, $diff);
            
            $arr[$i] += $sub;
            $it -= $sub;
        }
    }
    
    $add = intdiv($it, count($arr));
    $spread = $it % count($arr);

    for ($i = 0; $i <= $maxI; ++$i) {
        $arr[$i] += $add;
        
        if ($spread > 0) {
            ++$arr[$i];
            --$spread;
        }
    }
    
    return $arr;
}