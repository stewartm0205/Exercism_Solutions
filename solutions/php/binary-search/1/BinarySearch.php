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

function find(int $needle, array $haystack): int
{
    if (count($haystack)==0) return -1;
    $b=0;
    $e=count($haystack)-1;
    $m=intdiv($e,2);
    while(true){
        if ($haystack[$m] == $needle) return $m;
        if ($haystack[$b] == $needle) return $b;
        if ($haystack[$e] == $needle) return $e;
        if ($e==$b+1) return -1;
        if ($haystack[$m] > $needle) $e=$m;
        else $b=$m;
        $m=intdiv($b+$e,2);
    }

}
