<?php

// 1717 A. Madoka and Strange Thoughts
// _math_, _numbers_, _gcd_, _lcm_

fscanf(STDIN, '%u', $t);

while ($t--) {
    fscanf(STDIN, '%u', $n);

    echo (2 * (intdiv($n, 3)) + 2 * (intdiv($n, 2)) + $n) . PHP_EOL;
}

/*
g = gcd(a,b)
l = lcm(a,b)
l = a * b / g
a = g * a0
b = g * b0

Cases when l / g <= 3.

a * b / (g**2) <= 3;
(g ** 2) * a0 * b0 / (g**2) <= 3;

a0 * b0 <= 3;
Three cases:
- a0 * b0 = 3:
    a0 = 1, b0 = 3:
    (a, b) = (g, 3g);
    a0 = 3, b0 = 1:
    (a, b) = (3g, g);
- a0 * b0 = 2:
    a0 = 1, b0 = 2:
    (a, b) = (g, 2g);
    a0 = 2, b0 = 1:
    (a, b) = (2g, g);
- a0 * b0 = 1
    a0 = 1, b0 = 1
    (a, b) = (g, g)
 */
