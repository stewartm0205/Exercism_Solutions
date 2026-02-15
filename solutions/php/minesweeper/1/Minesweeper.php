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

function solve(string $minesweeperBoard): string
{
    $b=str_split($minesweeperBoard);
    $c=0;
    $r=0;
    $e=0;
    for ($i=0;$i<count($b);$i++) {
        if($b[$i]=='-') $c++;
        if($b[$i]=='|') $r++;
        if($b[$i]=='+') $e++;
        if(strpos("+-| *\n",$b[$i])===false) throw new InvalidArgumentException();
    }
    if ($r % 2 !=0) throw new InvalidArgumentException();
    if ($c % 2 !=0) throw new InvalidArgumentException();
    if ($c < 4 ) throw new InvalidArgumentException();
    if ($e != 4) throw new InvalidArgumentException();

    $c=intdiv($c,2);
    $r=intdiv($r,2);
    for ($j=0;$j<$r;$j++) {
        if ($b[spos($c,-1,$j)] !='|' || $b[spos($c,$c,$j)] != '|') throw new InvalidArgumentException();

    }
    $m=array();
    for ($j=0;$j<$r;$j++) {
        array_push($m,array());
        for ($i=0;$i<$c;$i++){
            array_push($m[$j],0);
        }
    }
    for ($j=0;$j<$r;$j++) {
        for ($i=0;$i<$c;$i++){
            if($b[spos($c,$i,$j)]==' ') {
                if ($b[spos($c,$i-1,$j-1)]=='*') $m[$j][$i]++;
                if ($b[spos($c,$i,$j-1)]=='*') $m[$j][$i]++;
                if ($b[spos($c,$i+1,$j-1)]=='*') $m[$j][$i]++;
                if ($b[spos($c,$i-1,$j)]=='*') $m[$j][$i]++;
                if ($b[spos($c,$i+1,$j)]=='*') $m[$j][$i]++;
                if ($b[spos($c,$i-1,$j+1)]=='*') $m[$j][$i]++;
                if ($b[spos($c,$i,$j+1)]=='*') $m[$j][$i]++;
                if ($b[spos($c,$i+1,$j+1)]=='*') $m[$j][$i]++;
            }
        }
    }
    for ($j=0;$j<$r;$j++) {
        for ($i=0;$i<$c;$i++){
            if ($m[$j][$i]>0) $b[spos($c,$i,$j)]=strval($m[$j][$i]);
        }
    }
    return implode($b);

}
function spos($c,$x,$y) {
    $spos=($c+3)*($y+1)+$x+2;
    return $spos;
}
