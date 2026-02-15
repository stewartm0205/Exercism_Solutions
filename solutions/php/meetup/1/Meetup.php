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

function meetup_day(int $year, string $month, string $which, string $weekday): DateTimeImmutable
{

    $fd=array("teenth"=>13,'first'=>1,'second'=>8,'third'=>15,'fourth'=>22,'last'=>31);
    $ld=array("teenth"=>19,'first'=>7,'second'=>14,'third'=>21,'fourth'=>28,'last'=>22);
    if ($month=='2' && $year%4!=0) $fd['last']=28;
    if ($month=='2' && $year%4==0) $fd['last']=29;
    if (in_array($month,array('4','6','9','11'))) $fd['last']=30;

    $dtstr=strval($year).'/'.$month.'/1';
    $d=new DateTimeImmutable($dtstr);
    if ($which!='last') {
        for ($dom=$fd[$which]; $dom<=$ld[$which]; $dom++) {
            $dtstr=strval($year).'/'.$month.'/'.$dom;
            $d=new DateTimeImmutable($dtstr);
            $dow=$d->format('l');
            if ($dow==$weekday) {
                return $d;
            }
        }
    } else {
        for ($dom=$fd[$which]; $dom>=$ld[$which]; $dom--) {
            $dtstr=strval($year).'/'.$month.'/'.$dom;
            $d=new DateTimeImmutable($dtstr);
            $dow=$d->format('l');
            if ($dow==$weekday) return $d;
        }
    }
}

