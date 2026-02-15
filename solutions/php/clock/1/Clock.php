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

class Clock
{
    private $hour;
    private $minute;

    public function __construct ($hour, $minute=0) {
        $this->minute = $minute;
        $this->hour = $hour;
        $this->standardize();
    }
    public function standardize() {
        $this->hour=($this->hour +
                    intdiv($this->minute,60)) % 24;
        $this->hour = $this->hour % 24;
        if ($this->hour<0) $this->hour=24+$this->hour;
        $this->minute = $this->minute % 60;
        if ($this->minute<0){
            $this->minute = 60 + $this->minute;
            $this->hour--;
        }

    }
    public function add($minute) {
        $this->minute+=$minute;
        $this->standardize();
        return new Clock($this->hour, $this->minute);
    }
    public function sub($minute) {
        $this->minute-=$minute;
        $this->standardize();
        return new Clock($this->hour, $this->minute);
    }
    public function __toString(): string
    {
        $h = sprintf("%02d",$this->hour);
        $m = sprintf("%02d",$this->minute);
        return $h.":".$m;
    }
}
