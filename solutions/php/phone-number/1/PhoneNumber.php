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

class PhoneNumber
{
    private $pn;

    public function __construct($phone) {
        $phone=preg_replace("/[ \(\).\-\+]+/","",$phone);
        if (strlen($phone)>11) throw new InvalidArgumentException('more than 11 digits');
        if (strlen($phone)==11 &&substr($phone,0,1)!='1') throw new InvalidArgumentException('11 digits must start with 1');
        if (preg_match("/[a-zA-Z]+/",$phone)) throw new InvalidArgumentException('letters not permitted');
        if (preg_match("/[@:!]+/",$phone)) throw new InvalidArgumentException('punctuations not permitted');
        if (strlen($phone)==11) $phone=substr($phone,1,10);
        if (strlen($phone)<10) throw new InvalidArgumentException('incorrect number of digits');
        if (substr($phone,0,1)=='0') throw new InvalidArgumentException('area code cannot start with zero');
        if (substr($phone,0,1)=='1') throw new InvalidArgumentException('area code cannot start with one');
        if (substr($phone,3,1)=='0') throw new InvalidArgumentException('exchange code cannot start with zero');
        if (substr($phone,3,1)=='1') throw new InvalidArgumentException('exchange code cannot start with one');
        $this->pn=$phone;
    }

    public function number(): string
    {
        return $this->pn;
    }
}
