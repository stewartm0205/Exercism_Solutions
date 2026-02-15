package BeerSong;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<sing>;

sub sing {
    my ($input) = @_;
    my $startBottles = $input->{"bottles"};
    my $takeDown = $input->{"verses"};
    my @verses;
    my $b=$startBottles;
    for (my $v=1;$v<=$takeDown;$v++){
        my $oneless = $b-1;
        if ($b > 2) {
            push(@verses,"$b bottles of beer on the wall, $b bottles of beer.",
            "Take one down and pass it around, $oneless bottles of beer on the wall.");
        } elsif ($b == 2) {
            push(@verses,"2 bottles of beer on the wall, 2 bottles of beer.",
            "Take one down and pass it around, 1 bottle of beer on the wall.");
        } elsif ($b == 1) {
            push(@verses,"1 bottle of beer on the wall, 1 bottle of beer.",
            "Take it down and pass it around, no more bottles of beer on the wall.");
        } elsif ($b == 0) {
            push(@verses,"No more bottles of beer on the wall, no more bottles of beer.",
           "Go to the store and buy some more, 99 bottles of beer on the wall.");
        }
        if ($v<$takeDown) {push(@verses,"");}
        $b--;
    }
    return join "\n", @verses;
}

1;
