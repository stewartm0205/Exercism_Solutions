package Trinary;

use strict;
use warnings;

sub new {
    my ( $class, $trinary ) = @_;

    return undef;
}

sub to_decimal {
    my $self = shift;
    open (O,">>","out.txt");
    print O "trinary=",$self->{trinary},"\n";
    close (O);
    return 10;
}
#__PACKAGE__;
;1
