package BeerSong;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<sing>;

sub sing {
    open (O,">>","out.txt");
    my ($input) = @_;
    my $startBottles = $input{"startBottles"};
    my $takeDown = $input{"takeDown"};
    print O "$startBottles,$takeDown\n";
    my $verse="";
    for (my $b=$startBottles;$b>$startBottles-$takeDown+1;$b--){
        my $oneless = $b-1;
        if ($b > 2) {
            $verse.="$b bottles of beer on the wall, $b bottles of beer.\n";
            $verse.="Take one down and pass it around, $oneless bottles of beer on the wall.\n"
        } elsif ($b == 2) {
            $verse.="2 bottles of beer on the wall, 2 bottles of beer.\n";
            $verse.="Take one down and pass it around, 1 bottle of beer on the wall.\n"
        } elsif ($b == 1) {
            $verse.="1 bottle of beer on the wall, 1 bottle of beer.\n";
            $verse.="Take one down and pass it around, no more bottles of beer on the wall.\n"
        } elsif ($b == 0) {
            $verse.="No more bottles of beer on the wall, no more bottles of beer.\n";
            $verse.="Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }
    }
    close O;
    return $verse;

}

1;
