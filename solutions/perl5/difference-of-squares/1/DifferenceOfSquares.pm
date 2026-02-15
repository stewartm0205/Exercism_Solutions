package DifferenceOfSquares;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<square_of_sum sum_of_squares difference_of_squares>;

sub square_of_sum {
    my ($number) = @_;
    my $s=0;
    foreach ((1..$number)){
        $s+=$_;
    }
    return $s*$s;
}

sub sum_of_squares {
    my ($number) = @_;
    my $s=0;
    foreach ((1..$number)){
        $s+=$_*$_;
    }
    return $s;
}

sub difference_of_squares {
    my ($number) = @_;
    my $diff = square_of_sum($number) - sum_of_squares ($number);
    return $diff;
}

1;
