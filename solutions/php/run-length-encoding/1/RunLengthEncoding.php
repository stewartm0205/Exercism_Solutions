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

function encode(string $input): string
{
    $ret="";
    $in=str_split($input);
    $i=0;
    $count=0;
    while ($i<count($in)) {
        if ($count==0) {
            $cc=$in[$i];
            $count++;
            $i++;
        }
        while ($i<count($in) && $cc==$in[$i]) {
            $count++;
            $i++;
        }
        if ($count==1) {
            $ret.=$cc;
        } else {
            $ret.=strval($count).$cc;
        }
        $count=0;
    }

    return $ret;
}

function decode(string $input): string
{
    $ret="";
    $i=0;
    $in=str_split($input);
    while ($i<count($in)) {
        $n="";
        if ($in[$i]>="0" && $in[$i]<="9") {
            $n.=$in[$i++];
            while ($in[$i]>="0" && $in[$i]<="9"){
                $n.=$in[$i];
                $i++;
            }
            $c=$in[$i];
            $ret.=str_repeat($c,intval($n));
        } else {
            $ret.=$in[$i];
        }
        $i++;
    }
    return $ret;
}
