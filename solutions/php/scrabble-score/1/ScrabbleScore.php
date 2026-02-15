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

function score(string $word): int
{
    $s=0;
    if (strlen($word)==0) return 0;
    foreach (str_split(strtoupper($word)) as $ch) {
        if (strpos("A, E, I, O, U, L, N, R, S, T",$ch)!==false) $s+=1;
        elseif (strpos("D, G",$ch)!==false) $s+=2;
        elseif (strpos("B, C, M, P",$ch)!==false) $s+=3;
        elseif (strpos("F, H, V, W, Y",$ch)!==false) $s+=4;
        elseif ($ch=="K") $s+=5;
        elseif (strpos("J, X",$ch)!==false) $s+=8;
        elseif (strpos("Q, Z",$ch)!==false) $s+=10;
    }
    return $s;
}
