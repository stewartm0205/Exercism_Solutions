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

function rebase(int $baseIn, array $sequence, int $baseOut)
{

    if (count($sequence)==0) return null;
    if (count($sequence)>0 && $sequence[0]==0) return null;
    if (!$baseIn) return null;
    if ($baseIn <=0) return null;
    if ($baseOut<=1) return null;

    /* convert sequence into decimal # */
    $dec=0;
    $mul=1;
    for ($i=count($sequence)-1;$i>=0;$i--) {
        if ($sequence[$i]>=$baseIn) return null;
        if ($sequence[$i]<0) return null;
        $dec+=$sequence[$i]*$mul;
        $mul*=$baseIn;
    }
    if ($dec==0) return null;
    /* convert from decimal # to baseOut */
    $seqOut=array();
    while($dec>=1) {
        array_unshift($seqOut,$dec % $baseOut);
        $dec=intdiv($dec,$baseOut);
    }
    return $seqOut;
}
