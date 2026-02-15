<?php

/*
 * By adding type hints and enabling strict type checking, code can become
 * easier to read, self-documenting and reduce the number of potential bugs.
 * By default, type declarations are non-strict, which means they will attempt
 * to change the original type to match the type specified by the
 * type-declaration.
 *
 * In other words, if you pass a string to a function requiring a float,
 * it will attempt to convert the string value to a float.
 *
 * To enable strict mode, a single declare directive must be placed at the top
 * of the file.
 * This means that the strictness of typing is configured on a per-file basis.
 * This directive not only affects the type declarations of parameters, but also
 * a function's return type.
 *
 * For more info review the Concept on strict type checking in the PHP track
 * <link>.
 *
 * To disable strict typing, comment out the directive below.
 */

declare(strict_types=1);

class Series
{
    private $series;

    public function __construct($series) {
        $this->series = $series;
    }
    public function largestProduct(int $span): int
    {
        if ($span==0) return 1;
        if (strlen($this->series)==0) throw new InvalidArgumentException();
        if ($span > strlen($this->series)) throw new InvalidArgumentException();
        if ($span<0) throw new InvalidArgumentException();
        $lsp=0;
        $digits=str_split($this->series);
        for ($i=0; $i<count($digits)-$span+1; $i++) {
            $p=1;
            for($j=0; $j<$span; $j++) {
                if ($digits[$i+$j]<"0" || $digits[$i+$j]>"9") throw new InvalidArgumentException();
                $p*=intval($digits[$i+$j]);
            }
            if ($p>$lsp) $lsp=$p;

        }
        return $lsp;
    }
}
