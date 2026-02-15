package Triangle;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<is_equilateral is_isosceles is_scalene>;

sub is_equilateral {

    my $a = @{$_[0]}[0];
    my $b = @{$_[0]}[1];
    my $c = @{$_[0]}[2];

    if ($a == 0) {return 0;}
    if ($a>$b+$c||$b>$a+$c||$c>$a+$b) {return 0;}
    if ($a == $b && $b == $c) {return 1;}
    return 0;
   
}

sub is_isosceles {
    my $a = @{$_[0]}[0];
    my $b = @{$_[0]}[1];
    my $c = @{$_[0]}[2];
    if ($a == 0 || $b == 0 || $c==0 ) {return 0;}
    if ($a>$b+$c||$b>$a+$c||$c>$a+$b) {return 0;}
    if ($a==$b || $a==$c || $b==$c ) {return 1;}
    return 0;
}

sub is_scalene {
    my $a = @{$_[0]}[0];
    my $b = @{$_[0]}[1];
    my $c = @{$_[0]}[2];
    if ($a == 0 || $b == 0 || $c==0 ) {return 0;}
    if ($a>$b+$c||$b>$a+$c||$c>$a+$b) {return 0;}
    if ($a == $b && $b == $c) {return 0;}
    if ($a==$b || $a==$c || $b==$c ) {return 0;}
    return 1;
}

1;
