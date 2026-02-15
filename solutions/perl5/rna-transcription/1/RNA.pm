package RNA;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<to_rna>;

sub to_rna {

    my ($dna) = @_;

    my $rna="";
    foreach my $l (split //, $dna)
    {

        if ($l eq 'G') {
            $rna.='C';
        } elsif ($l eq 'C') {
            $rna.='G';
        } elsif ($l eq 'T') {
            $rna.='A';
        } elsif ($l eq 'A') {
            $rna.='U';
        }
    }

    return $rna;
}

1;
