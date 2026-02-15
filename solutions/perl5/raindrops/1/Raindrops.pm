package Raindrops;
use strict;
use warnings;
use Exporter 'import';
our @EXPORT_OK = qw(raindrop);

sub raindrop {
  my ($number) = @_ ;
  my ($rd) = "";
  if ($number % 3 == 0) {$rd = "Pling";}
  if ($number % 5 == 0) {$rd = $rd . "Plang";}
  if ($number % 7 == 0) {$rd = $rd . "Plong";}
  if ($rd eq "") {return $number;} else { return $rd;}
}

1;
