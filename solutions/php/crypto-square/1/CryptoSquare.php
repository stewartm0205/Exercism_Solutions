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

function crypto_square(string $plaintext): string
{
    if ($plaintext=="") return "";
    $text="";
    for($i=0;$i<strlen($plaintext);$i++) {
        if (strpos(" @,%!.",substr($plaintext,$i,1))===false) {
            $text.=strtolower(substr($plaintext,$i,1));
        }
    }
    $r=intval(sqrt(strlen($text)));
    if ($r<1) $r=1;
    $c=intdiv(strlen($text),$r);
    if (($c-$r)>1) {$r++; $c--;}
    if ($r*$c<strlen($text)) $c++;
    $lines=array();
    for ($i=0;$i<$r;$i++) {
        array_push($lines,substr($text.str_repeat(" ",$c+2),$i*$c,$c));
    }
    $code="";
    $cc=0;
    for ($i=0;$i<$c;$i++) {
        for ($j=0;$j<$r;$j++) {
            if ($cc==$r) {
                $code.=" ";
                $cc=0;
            }
            $code.=substr($lines[$j],$i,1);
            $cc++;
        }
    }
    return $code;
}
