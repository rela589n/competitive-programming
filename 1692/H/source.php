<?php

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);
    $ar = fscanf(STDIN, str_repeat('%u ', $n));

    /** @var array<int, array<int, int>> $pos */
    $pos = array_fill_keys($ar, []);

    foreach ($ar as $key => $it) {
        $pos[$it][] = $key;
    }

    $maxP = 1;
    $maxL = 0;
    $maxR = 0;
    $maxIt = $ar[0];

    foreach ($pos as $it => $occ) {
        $mI = count($occ);

        if ($maxP >= $mI) {
            continue;
        }

        // matrix, holding optimal powers if start from the index
        $dm = array_fill(0, $mI, 1);// array_fill_keys ($occ, 1);
        $dmEnds = array_keys($dm);

        for ($i = $mI - 2; $i >= 0; --$i) {
            $currentPos = $occ[$i];
            $nextPos = $occ[$i + 1];

            $gap = $nextPos - $currentPos - 1;

            $powerWithGap = 1 + $dm[$i + 1] - $gap;

            if ($powerWithGap > 1) {
                $dm[$i] = $powerWithGap;
                $dmEnds[$i] = $dmEnds[$i + 1];

                if ($maxP < $powerWithGap) {
                    $maxP = $powerWithGap;
                    $maxL = $currentPos;
                    $maxR = $occ[$dmEnds[$i]];
                    $maxIt = $it;
                }
            }
        }
    }

    fprintf(STDOUT, '%u %u %u' . PHP_EOL, $maxIt, $maxL + 1, $maxR + 1);
}
/*

We would check every number and:
- each idex will have weight

1
1
1

1
5
1 2 2 3 4

1
6
1 2 2 3 2 2
// 2 2 6

1
3
1 2 3

 */
