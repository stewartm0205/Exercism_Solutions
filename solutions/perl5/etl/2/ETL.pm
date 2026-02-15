package ETL;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<transform>;

sub transform {
    my ($score) = @_;
    my %result;
    foreach my $key (keys % {$score}){
        my @letters = @{$score->{$key}};
        $result{lc $_} = $key for (@letters);
    }
    return \%result;
}

1;
