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

function calculate(string $input): int
{
    if (preg_match('/What is (-*[0-9]+)\?/',$input,$out)) {
        return intval($out[1]);
    } elseif (preg_match('/What is (-*[0-9]+) (plus|minus|multiplied by|divided by) (-*[0-9]+)\?/',$input,$out)) {
        $a=intval($out[1]);
        $b=intval($out[3]);
        if ($out[2]=='plus') return $a+$b;
        elseif ($out[2]=='minus') return $a-$b;
        elseif ($out[2]=='multiplied by') return $a*$b;
        else return $a/$b;
    }  elseif (preg_match('/What is (-*[0-9]+) (plus|minus|multiplied by|divided by) (-*[0-9]+) (plus|minus|multiplied by|divided by) (-*[0-9]+)\?/',$input,$out)) {

        $a=intval($out[1]);
        $b=intval($out[3]);
        $c=intval($out[5]);

        if ($out[2]=='plus') $r = $a+$b;
        elseif ($out[2]=='minus') $r = $a-$b;
        elseif ($out[2]=='multiplied by') $r = $a*$b;
        else $r = $a/$b;
        if ($out[4]=='plus') $r+=$c;
        elseif ($out[4]=='minus') $r-= $c;
        elseif ($out[4]=='multiplied by') $r*= $c;
        else $r /= $c;
        return $r;
    } else {
        throw new InvalidArgumentException();
    }
}
