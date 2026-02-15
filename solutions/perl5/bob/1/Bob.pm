# Declare package 'Bob' with version
package Bob 4;
use strict;
use warnings;
use Exporter 'import';
our @EXPORT_OK = qw(hey);

sub hey {
  my ($msg) = @_;
  #print "$msg \n";
 if ($msg =~ /^([A-Z!]| )+\? *$/) {return ("Calm down, I know what I'm doing!");}
 if ($msg =~ /^[ \t\r\n]*$/) {return ("Fine. Be that way!");}
 if ($msg =~ /^.+\? *$/) {return "Sure.";}
 $msg =~ /(.)(.*)/;
 $a = "T";
 my @ucw = split(/[^A-Z]+/,$2);
 foreach(@ucw) {
	#print "<$_>\n";
	if (!($_ eq "" || $_ eq "DMV" || $_ eq "OK")) {$a = "F"};
 }
 #print "a=$a\n";
 if ($a eq "F") {return ("Whoa, chill out!");} 
 return ("Whatever.");
}

1;
