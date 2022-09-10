<?php

fscanf(STDIN, '%d', $t);

while ($t--) {
    fscanf(STDIN, '%u:%u %u', $hh, $mm, $n);
    $time = $hh * 60 + $mm;

    $res = 0;

    $used = [];

    for ($i = 0; ; $i += $n) {
        $ctime = ($time + $i) % 1440;

        if (isset($used[$ctime])) {
            break;
        }

        $used[$ctime] = true;

        $h = intdiv($ctime, 60);
        $m = $ctime % 60;

        // 12 21
        if (($h % 10 === intdiv($m, 10)) && (intdiv($h, 10) === $m % 10)) {
            ++$res;
        }
    }

    fprintf(STDOUT, "%u\n", $res);
}
// 24 20
// 00 20


/*


1
11:11 11
//16

1
22:30 27


1
12:21 1440
//1

1
23:00 60
// 1

1
23:21 60
// 1

1
00:42 60
// 0

 */
