<?php

declare(strict_types=1);

use JetBrains\PhpStorm\Immutable;

#[Immutable]
final class BinarySearchTest extends \PHPUnit\Framework\TestCase
{
    public function testEmptyArray(): void
    {
        self::assertSame(0, upper_bound([], 123));
    }

    public function testFindsBeyondLowestItem(): void
    {
        self::assertSame(0, upper_bound([10, 20], 1));
    }

    public function testFindsLowestItem(): void
    {
        self::assertSame(1, upper_bound([10, 20, 30], 10));
    }

    public function testFindsBeyondGreatestItem(): void
    {
        self::assertSame(3, upper_bound([1, 2, 3], 100));
    }

    public function testFindsGreatestItem(): void
    {
        self::assertSame(3, upper_bound([1, 2, 3], 3));
    }

    public function testFindsOddMiddleItem(): void
    {
        self::assertSame(3, upper_bound([1, 2, 2, 3, 4], 2));
    }

    public function testFindsEvenMiddleItem(): void
    {
        self::assertSame(3, upper_bound([1, 2, 2, 3], 2));
    }
}

function upper_bound(array $ar, int $value): int
{
    $resultPointer = 0;
    $remainingItems = count($ar);

    while ($remainingItems) {
        $half = $remainingItems >> 1;
        $middle = $resultPointer + $half;

        if ($ar[$middle] <= $value) {
            $resultPointer = $middle + 1;
            $remainingItems -= $half + 1;
        } else {
            $remainingItems = $half;
        }
    }

    return $resultPointer;
}
