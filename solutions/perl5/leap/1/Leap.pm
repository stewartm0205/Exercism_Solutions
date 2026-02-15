# Declare package 'Leap'
package Leap;
use strict;
use warnings;
use Exporter 'import';
our @EXPORT_OK = qw(is_leap);

sub is_leap {
  my ($year) = @_;
  if ($year % 400 == 0 || ($year % 100 != 0 && $year % 4 == 0)) {return 1;}
  return 0;
}

1;
