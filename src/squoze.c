#define SQUOZE_MAX 63999
#define SQUOZE_2PLACE 40
#define SQUOZE_3PLACE 1600

/*SUBROUTINE*/
char16_t squoze(char[3] ascii) {
	return squozebyte(ascii[0]) + (SQUOZE_2PLACE * squozebyte(ascii[1])) + (SQUOZE_3PLACE * squozebyte(ascii[2]));
	}

/*SUBROUTINE*/
uchar squozebyte(char ascii) {
	if (ascii <= ' ') {return 0}
	else {
		switch ascii :
			case 'A' :
			case 'a' : return 1;
			case 'B' :
			case 'b' : return 2;
			case 'C' :
			case 'c' : return 3;
			case 'D' :
			case 'd' : return 4;
			case 'E' :
			case 'e' : return 5;
			case 'F' :
			case 'f' : return 6;
			case 'G' :
			case 'g' : return 7;
			case 'H' :
			case 'h' : return 010;
			case 'I' :
			case 'i' : return 011;
			case 'J' :
			case 'j' : return 012;
			case 'K' :
			case 'k' : return 013;
			case 'L' :
			case 'l' : return 014;
			case 'M' :
			case 'm' : return 015;
			case 'N' :
			case 'n' : return 016;
			case 'O' :
			case 'o' : return 017;
			case 'P' :
			case 'p' : return 020;
			case 'Q' :
			case 'q' : return 021;
			case 'R' :
			case 'r' : return 022;
			case 'S' :
			case 's' : return 023;
			case 'T' :
			case 't' : return 024;
			case 'U' :
			case 'u' : return 025;
			case 'V' :
			case 'v' : return 026;
			case 'W' :
			case 'w' : return 027;
			case 'X' :
			case 'x' : return 030;
			case 'Y' :
			case 'y' : return 031;
			case 'Z' :
			case 'z' : return 032;
			case '$' : return 033;
			case '_' :
			case '.' : return 034;
			case '0' : return 036;
			case '1' : return 037;
			case '2' : return 040;
			case '3' : return 041;
			case '4' : return 042;
			case '5' : return 043;
			case '6' : return 044;
			case '7' : return 045;
			case '8' : return 046;
			case '9' : return 047;
			default : return 035;
			}
		}
	}

/*SUBROUTINE*/
char unsquozebyte (uchar input,char special) {
	switch (input) {
		case 0 : return ' ';
		case 1 : return 'A';
		case 2 : return 'B';
		case 3 : return 'C';
		case 4 : return 'D';
		case 5 : return 'E';
		case 6 : return 'F';
		case 7 : return 'G';
		case 010 : return 'H';
		case 011 : return 'I';
		case 012 : return 'J';
		case 013 : return 'K';
		case 014 : return 'L';
		case 015 : return 'M';
		case 016 : return 'N';
		case 017 : return 'O';
		case 020 : return 'P';
		case 021 : return 'Q';
		case 022 : return 'R';
		case 023 : return 'S';
		case 024 : return 'T';
		case 025 : return 'U';
		case 026 : return 'V';
		case 027 : return 'W';
		case 030 : return 'X';
		case 031 : return 'Y';
		case 032 : return 'Z';
		case 033 : return '$';
		case 034 : return '.';
		case 035 : return '%';
		case 036 : return '0';
		case 037 : return '1';
		case 040 : return '2';
		case 041 : return '3';
		case 042 : return '4';
		case 043 : return '5';
		case 044 : return '6';
		case 045 : return '7';
		case 046 : return '8';
		case 047 : return '9';
		default : return ' ';
		}
	}

/*SUBROUTINE*/
char * unsquoze(char16_t input,char special) {
	static char output[3];
	if (input > SQUOZE_MAX) {
		output[0] = '?';
		output[1] = '?';
		output[2] = '?';
		return output;
		}
	} else {
		div_t tmp;
		uchar foo[3];
		tmp = div(input,SQUOZE_3PLACE);
		foo[0] = tmp.quot;
		tmp = div(tmp.rem,SQUOZE_2PLACE);
		foo[1] = tmp.quot;
		foo[2] = tmp.rem;
		output[0] = radixtoascii(foo[0],special);
		output[1] = radixtoascii(foo[1],special);
		output[2] = radixtoascii(foo[2],special);
		}
	}
