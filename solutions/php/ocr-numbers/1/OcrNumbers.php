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

function recognize(array $input): string
{
    if (count($input)%4!=0) throw new InvalidArgumentException;
    if (strlen($input[0])%3 != 0) throw new InvalidArgumentException;
    $d="";
    for ($k=0;$k<count($input);$k+=4) {
        for ($i=0;$i<strlen($input[0]);$i+=3) {
            $c=array();

            for($j=0;$j<4;$j++)
                array_push($c,substr($input[$k+$j],$i,3));

            $d.=recogdigit($c);
        }
        if (count($input)>4 && count($input)-$k>4) $d.=",";
    }
    return $d;
}

function recogdigit ($c) {
    if ($c[0]==" _ " &&
        $c[1]=="| |" &&
        $c[2]=="|_|" &&
        $c[3]=="   ") return "0";

    if ($c[0]=="   " &&
        $c[1]=="  |" &&
        $c[2]=="  |" &&
        $c[3]=="   ") return "1";

    if ($c[0]==" _ " &&
        $c[1]==" _|" &&
        $c[2]=="|_ " &&
        $c[3]=="   ") return "2";

    if ($c[0]==" _ " &&
        $c[1]==" _|" &&
        $c[2]==" _|" &&
        $c[3]=="   ") return "3";

    if ($c[0]=="   " &&
        $c[1]=="|_|" &&
        $c[2]=="  |" &&
        $c[3]=="   ") return "4";

    if ($c[0]==" _ " &&
        $c[1]=="|_ " &&
        $c[2]==" _|" &&
        $c[3]=="   ") return "5";

    if ($c[0]==" _ " &&
        $c[1]=="|_ " &&
        $c[2]=="|_|" &&
        $c[3]=="   ") return "6";

    if ($c[0]==" _ " &&
        $c[1]=="  |" &&
        $c[2]=="  |" &&
        $c[3]=="   ") return "7";

    if ($c[0]==" _ " &&
        $c[1]=="|_|" &&
        $c[2]=="|_|" &&
        $c[3]=="   ") return "8";

    if ($c[0]==" _ " &&
        $c[1]=="|_|" &&
        $c[2]==" _|" &&
        $c[3]=="   ") return "9";

    return "?";
}
