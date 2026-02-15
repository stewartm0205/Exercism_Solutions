package TwoFer;
use strict;
use warnings;
use Exporter 'import';
our @EXPORT_OK = qw(two_fer);

sub two_fer {
  my ($name) = @_;
  if ($name) {
	return "One for $name, one for me.";
  } else {	
	return "One for you, one for me.";
	}
  return undef;
}

1;
