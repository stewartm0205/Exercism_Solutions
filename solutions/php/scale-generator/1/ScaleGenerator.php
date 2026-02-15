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

class Scale
{
    public $name;
    public $pitches;
    public function __construct(string $tonic, string $scaleName, string $pattern=null)
    {
        $snotes=array("A","A#","B","C","C#","D","D#","E","F","F#","G","G#");
        $fnotes=array("A","Bb","B","C","Db","D","Eb","E","F","Gb","G","Ab");
        $this->name=strtoupper($tonic) . " " . $scaleName;
        $this->pitches=array();
        if ($scaleName=="chromatic") {
            if (strpos('CGDAEB',$tonic)!==false) $notes=$snotes;
            else $notes=$fnotes;
            $si=array_search($tonic,$notes);
            for($i=0;$i<12;$i++)
                array_push($this->pitches,$notes[($si+$i) % 12]);
        } else {

            if (strpos('G,D,A,E,B,F#,C,a,e,b,f#,g#,d#,',$tonic.',')!==false) $notes=$snotes;
            else $notes=$fnotes;
            $i=0;
            $pi=0;
            if (strlen($tonic)==2) $key=strtoupper(substr($tonic,0,1)).substr($tonic,1,1);
            else $key=strtoupper($tonic);
            $si=array_search($key,$notes);
            while ($i<12) {
                array_push($this->pitches,$notes[($si+$i) % 12]);
                if ($pattern[$pi]=='M') $i+=2;
                elseif ($pattern[$pi]=='A') $i+=3;
                else $i++;
                $pi++;
            }
        }
    }

}
