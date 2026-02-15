package Hamming;
use strict;
use warnings;
use Exporter 'import';
our @EXPORT_OK = qw(grains_on_square total_grains);

sub compute {
  my($strand1, $strand2) = @_;
  if (length($strand1) != length($strand2)) {die "DNA strands must be of equal length";}
  my($dist) = 0;
  for (my($i)=0; $i<length($strand1); $i++) {
    if (substr($strand1, $i, 1) ne substr($strand2, $i, 1)){ $dist++;}
  }
  return $dist
}

1;