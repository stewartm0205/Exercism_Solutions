package Gigasecond;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<add_gigasecond>;

sub add_gigasecond {
    use Time::Piece;
    my ($time) = @_;
    my $dt = Time::Piece->strptime($time,'%Y-%m-%dT%H:%M:%S') + 1000000000;
    return $dt->strftime('%Y-%m-%dT%H:%M:%S');
}

1;
