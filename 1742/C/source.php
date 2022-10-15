<?php

// 1742 C. Stripes (Painting)
// _matrix_, _strings_, *900

fscanf(STDIN, '%u', $t);

$red = 'RRRRRRRR';

while ($t--) {
    $lines = [];
    fgets(STDIN);
    for ($i = 0; $i < 8; ++$i) {
        fscanf(STDIN, '%s', $lines[$i]);
    }

    if (in_array($red, $lines, true)) {
        echo 'R'.PHP_EOL;
    }  else {
        echo 'B'.PHP_EOL;
    }
}

/*

4

....B...
....B...
....B...
RRRRRRRR
....B...
....B...
....B...
....B...

RRRRRRRB
B......B
B......B
B......B
B......B
B......B
B......B
RRRRRRRB

RRRRRRBB
.B.B..BB
RRRRRRBB
.B.B..BB
.B.B..BB
RRRRRRBB
.B.B..BB
.B.B..BB

........
........
........
RRRRRRRR
........
........
........
........


 */
