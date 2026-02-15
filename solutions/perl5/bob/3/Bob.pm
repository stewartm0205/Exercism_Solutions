# Declare package 'Bob' with version
package Bob 4;
use strict;
use warnings;
use Exporter 'import';
our @EXPORT_OK = qw(hey);

sub hey {
 my ($msg) = @_;
 if ($msg eq uc($msg) && $msg =~ /^.*[A-Z!]{2,}.*\? *$/) {return ("Calm down, I know what I'm doing!");}
 if ($msg =~ /^[ \t\r\n]*$/) {return ("Fine. Be that way!");}
 if ($msg =~ /^.+\? *$/) {return "Sure.";}
 if ($msg eq uc($msg) && $msg =~ /^.*[A-Z!]{2,}.*$/) {return ("Whoa, chill out!");} 
 return ("Whatever.");
}

1;
