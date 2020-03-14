use strict;
use warnings;

open (my $input,'<',$ARGV[0]);
open (my $output,'>',$ARGV[1]);

my @lines;
{
my $state = !1;
my $tmp;
until (eof($input)) {
	$tmp = <$input>;
	chomp $tmp;
	if ($state) {
		if (index($tmp,'%>') != -1) {
			$state = !1;
			push(@lines,'%>;');
			push(@lines,'');
		} else {
			unless (substr($tmp,-1) eq ';') {
				$tmp = split(';',$tmp,2);
				$tmp .= ';';
				}
			my $i = index($tmp,'*');
			my $j = index($tmp,';');
			if (index($tmp,'*') < 0) {
				push(@lines,$tmp);
			} else {
				$tmp =~ m/.*?[*]([^*]*?);/;
				$tmp = 'off_t ' . $1;
				if (index($tmp,'*') >= 0) {
					push(@lines,'#error fix this');
					}
				push(@lines,$tmp);
			}
		}
	} else {	
		if (index($tmp,'<%') != -1) {
			my @tmp2 = split(" ",$tmp);
			$tmp2[1] = 'WR_' . $tmp2[1];
			$tmp = join(' ',@tmp2);
			$state = !0;
			push(@lines,$tmp);
			}
		}
	}
}

foreach (@lines) {
	say $output $_;
	}
