package Luhn;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<is_luhn_valid>;

sub is_luhn_valid {
    my ($input) = @_;
    $input=~s/ //g;
    my $even=0;
    my $s = 0;
    if ($input eq '0') {return 0;}
    for (my $i=length($input)-1;$i>=0;$i--){
        my $d = substr($input,$i,1);
        if ($d lt '0' || $d gt '9') {return 0;}
        if ($even) {
            $even=0;
            $d *= 2;
            if ($d > 9) {
                $d-=9;
            }
        } else {
            $even=1;
        }
        $s+=$d;
    }
    if ($s % 10 == 0 ){
        return 1;
    } else {
        return 0;
    }
}

1;
