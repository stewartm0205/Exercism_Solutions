package Gigasecond;

use strict;
use warnings;
use feature qw<say>;

use Exporter qw<import>;
our @EXPORT_OK = qw<add_gigasecond>;

sub add_gigasecond {
    my ($time) = @_;
    use DateTime;
	my ($date,$tm)=split(/T/,$time);
    my ($year,$mon,$day)=split(/-/,$date);
    my ($hr, $min, $sec)=split(/:/,$tm);
    $hr ||=0;
    $min ||=0;
    $sec ||=0;
    my $dt = DateTime->new(year=>$year, month=>$mon, day=>$day, hour=>$hr, minute=>$min, second=>$sec);

    $dt->add(seconds=>1000000000);
    return $dt;
}

1;
