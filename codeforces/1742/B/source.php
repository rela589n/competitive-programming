<?php

// 1742 B. Increasing
// _impl_, _sorting_, *800

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);
    $ar = fscanf(STDIN, str_repeat('%u ', $n));
    sort($ar);

    $last = -1;
    $res = true;
    foreach($ar as $it) {
        if ($last < $it) {
            $last = $it;
            continue;
        }

        $res = false;
        break;
    }

    echo ($res ? 'YES' : 'NO').PHP_EOL;
}
