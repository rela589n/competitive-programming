<?php

$q = (int)readline();

$set = [];
$solution = new CacheProxySolution();

while ($q--) {
    $data = explode(' ', readline());
    $type = $data[0];

    if ('1' === $type) {
        $solution->push((float)$data[1]);
    } else {
        echo $solution->query().PHP_EOL;
    }
}

class Solution
{
    protected $set = [];
    protected $count = 0;

    protected $sumUpTo = [-1 => 0];
    protected $sumUp = -1;

    public function push(float $data): void
    {
        $this->set [] = $data;
        ++$this->count;
    }

    public function query()
    {
        if ($this->count <= 1) {
            return 0;
        }

        return $this->fx($this->ternarySearch());
    }

    public function fx(int $upTo): float
    {
        $num = $this->calcSum($upTo);
        $den = $upTo + 1;

        if ($this->count - 1 !== $upTo) {
            $num += $this->set[$this->count - 1];
            ++$den;
        }

        return $this->set[$this->count - 1] - $num / $den;
    }

    protected function calcSum($upTo): float
    {
        for ($i = $this->sumUp + 1; $i <= $upTo; ++$i) {
            $this->sumUpTo[$i] = $this->sumUpTo[$i - 1] + $this->set[$i];
        }

        return $this->sumUpTo[$upTo];
    }

    protected function ternarySearch(): int
    {
        $l = 0;
        $r = $this->count - 1;

        return $this->runTernarySearchFor($l, $r);
    }

    protected function runTernarySearchFor(int $l, int $r): int
    {
        $iterations = 0;

        while ($r - $l > 8 && $iterations < 32) {
            $m1 = $l + (int)(($r - $l) / 3);
            $m2 = $r - (int)(($r - $l) / 3);

            if ($m1 >= $m2) {
                break;
            }

            $fl = $this->fx($l);
            $fx1 = $this->fx($m1);
            $fx2 = $this->fx($m2);

            if ($fx1 < $fx2) {
                $l = $m1;
            } elseif ($fl > $fx1) {
                $r = $m1;
            } elseif ($fx1 > $fx2) {
                $r = $m2;
            } else {
                $l = $m1;
                $r = $m2;
            }

            ++$iterations;
        }

        $max = -INF;
        $maxIndx = -1;

        for ($i = $l; $i <= $r; ++$i) {
            $fx = $this->fx($i);

            if ($fx > $max) {
                $max = $fx;
                $maxIndx = $i;
            } else {
                break;
            }
        }

        if ($maxIndx === -1) {
            throw new \RuntimeException('Out of range');
        }

        return $maxIndx;
    }
}

class CacheProxySolution extends Solution
{
    private $fxCache = [];

    private $ternaryCache = [];

    private $lastTernaryL = null;

    public function fx(int $upTo): float
    {
        return $this->fxCache[$this->count][$upTo]
            ?? ($this->fxCache[$this->count][$upTo] = parent::fx($upTo));
    }

    protected function ternarySearch(): int
    {
        return $this->ternaryCache[$this->count]
            ?? ($this->ternaryCache[$this->count] = $this->evaluateCacheForTernarySearch());
    }

    protected function evaluateCacheForTernarySearch(): int
    {
        if (null === $this->lastTernaryL) {
            return parent::ternarySearch();
        }

        return parent::runTernarySearchFor($this->lastTernaryL, $this->count - 1);
    }

    protected function runTernarySearchFor(int $l, int $r): int
    {
        return $this->lastTernaryL = parent::runTernarySearchFor($l, $r);
    }

    public function push(float $data): void
    {
        if ($data === ($this->set[$this->count - 1] ?? null)) {
            $this->ternaryCache[$this->count + 1] = $this->ternaryCache[$this->count];
            $this->fxCache[$this->count + 1] = $this->fxCache[$this->count];
        }

        parent::push($data);
    }
}
