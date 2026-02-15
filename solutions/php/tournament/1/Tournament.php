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

class Tournament
{
    protected $team = array();
    protected $win=[];
    protected $loss=[];
    protected $draw=[];
    protected $points=[];
    protected $matches=[];


    public function __construct()
    {

    }
    public function tally($scores) {

        $tally="Team                           | MP |  W |  D |  L |  P";
        if ($scores=="") return $tally;
        $contests=explode("\n",$scores);
        foreach($contests as $contest){
            $result=explode(';',$contest);

            if ($result[2]=='win') {
                if (array_key_exists($result[0],$this->points)) $this->points[$result[0]]+=3;
                else $this->points[$result[0]]=3;
                if (array_key_exists($result[0],$this->win)) $this->win[$result[0]]++;
                else $this->win[$result[0]]=1;
                if (array_key_exists($result[1],$this->loss)) $this->loss[$result[1]]++;
                else $this->loss[$result[1]]=1;
                if (!array_key_exists($result[1],$this->points)) $this->points[$result[1]]=0;
            }
            if ($result[2]=='loss') {
                if (array_key_exists($result[1],$this->points)) $this->points[$result[1]]+=3;
                else $this->points[$result[1]]=3;
                if (array_key_exists($result[1],$this->win)) $this->win[$result[1]]++;
                else $this->win[$result[1]]=1;
                if (!array_key_exists($result[0],$this->points)) $this->points[$result[0]]=0;
                if (array_key_exists($result[0],$this->loss)) $this->loss[$result[0]]++;
                else $this->loss[$result[0]]=1;
            }
            if ($result[2]=='draw') {
                if (array_key_exists($result[0],$this->points)) $this->points[$result[0]]+=1;
                else $this->points[$result[0]]=1;
                if (array_key_exists($result[0],$this->draw)) $this->draw[$result[0]]++;
                else $this->draw[$result[0]]=1;
                if (array_key_exists($result[1],$this->points)) $this->points[$result[1]]+=1;
                else $this->points[$result[1]]=1;
                if (array_key_exists($result[1],$this->draw)) $this->draw[$result[1]]++;
                else $this->draw[$result[1]]=1;
            }
            if (array_key_exists($result[0],$this->matches)) $this->matches[$result[0]]++;
            else $this->matches[$result[0]]=1;
            if (array_key_exists($result[1],$this->matches)) $this->matches[$result[1]]++;
            else $this->matches[$result[1]]=1;
        }
        uksort($this->points,
                function($a,$b){
                    if ($this->points[$a] == $this->points[$b]) {
                        return strcmp($a,$b);
                    }
                    return ($this->points[$a]<$this->points[$b]) ? 1 : -1;
                });


        foreach ($this->points as $team => $point){
            $tally.="\n";
            if (array_key_exists($team,$this->win)) $w=$this->win[$team];
            else $w=0;
            if (array_key_exists($team,$this->draw)) $d=$this->draw[$team];
            else $d=0;
            if (array_key_exists($team,$this->loss)) $l=$this->loss[$team];
            else $l=0;
            $tally.=sprintf("%-30s |  %d |  %d |  %d |  %d |  %d",
                    $team,$this->matches[$team], $w,$d,$l,$point);
        }

        return $tally;
    }
}


