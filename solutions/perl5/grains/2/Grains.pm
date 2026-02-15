package Grains;
use strict;
use warnings;
use Exporter 'import';
our @EXPORT_OK = qw(grains_on_square total_grains);

sub grains_on_square {
  my($sq) = @_;
  if ($sq < 1 || $sq>64) {die;}
  my($grains) = 1;
  for (my($i)=2; $i<=$sq; $i++) {
    $grains *=  2;
  }
  return $grains
}

sub total_grains {
	my($tot) = 0;
	for (my($i)=1; $i<=64; $i++) {
		$tot += grains_on_square ($i);
	}
	return $tot;
}

1;
