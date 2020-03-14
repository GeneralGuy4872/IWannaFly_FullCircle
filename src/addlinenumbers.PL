use strict;
use warnings;

open (my $input,'<',$ARGV[0]);
open (my $output,'>',$ARGV[1]);
my $n = 1000;
my $line;

until(eof($input)) {
	$line = <$input>;
	printf $output '/*';
	printf $output $n;
	printf $output '*/ ';
	printf $output $line;
	$n += 1000;
	}
