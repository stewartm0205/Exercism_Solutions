package Trinary;

use strict;
use warnings;

sub new {
    my ( $class, $n ) = @_;
    my $self = \$n;
    bless $self, $class;
    return $self;
}

sub to_decimal {
    my $self = shift;
    my $dec = 0;
    my $mult = 1;
    for my $td (reverse(split(//,$$self))) {
        if ($td ge '0' && $td le '9') {
            $dec += $td * $mult;
            $mult *=3;
        }
    }
    return $dec;
}

1;
