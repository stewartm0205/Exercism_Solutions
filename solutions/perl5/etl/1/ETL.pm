package ETL;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<transform>;

sub transform {
    open(O,">>","out.txt");
    my ($in) = @_;
    print O "in= $in \n";
    foreach (keys %{$in}) {
        print O $ $_,":",$in->{$ $_},"\n";
        #my @let=@($in->{$_});
        #foreach (@let) {
       #     print O "lets=",$_,"\n";
       # }
    }
    close O;
    return undef;
}

1;
