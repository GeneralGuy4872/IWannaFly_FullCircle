%{
extern yylval;
extern std::vector<char*> garbage;
%}

IDENT	[A-Za-z_][A-Za-z0-9$_:]*
INTERGER	[+-]?[0-9]+
FLOAT	[+-]?([0-9]*\.[0-9]+([eE][-+]?[0-9]+)?)
HEX	("0x"|"$")[0-9A-Fa-f]+
BIN	"%"[01]+
OCTAL	"@"[0-7]+

ESCAPE_OCTAL	"\\"[0-7]([0-7][0-7]?)?
ESCAPE_HEX	"\\x"[0-9A-Fa-f][0-9A-Fa-f]

SEND	("\0"|[\003-\004]|[\030-\032]|<<EOF>>)
%x STRING
%%
{FLOAT}	{yylval.f = atof(yytext); return TOK_FLOAT;}
{INTERGER}	{yylval.l = strtol(yytext,NULL,10); return TOK_NUM;}
{HEX}	{yylval.l = strtol(yytext,NULL,16); return TOK_NUM;}
{IDENT}	{
	yylval.str = calloc(strlen(yytext) + 1,sizeof(char));
	strcpy(yylval.str,yytext);
	iwf$$commandline$$garbage$insert(yylval.str);
	return TOK_IDENT;
	}
{OCTAL}	{yylval.l = strtol(yytext,NULL,8); return TOK_NUM;}
"\""	{yystringbuffer$clear();BEGIN(STRING);return TOK_STR_FILLER;}
"!"	{return '!';}
"+"	{return '+';}
"-"	{return '-';}
"*"	{return '*';}
"/"	{return '/';}
"%"	{return '%';}
"<"	{return '<';}
"="	{return '=';}
">"	{return '>';}
";"	{return ';';}
"&"	{return '&';}
"|"	{return '|';}
"~"	{return '~';}
{SEND}	return 0;
[.]
<STRING>"\\\\"	{yystringbuffer$push_back('\\');return TOK_STR_FILLER;}
<STRING>{ESCAPE_OCTAL}	{yystringbuffer$push_back(strtol(yytext+1,NULL,8);return TOK_STR_FILLER;}
<STRING>{ESCAPE_HEX}	{yystringbuffer$push_back(strtol(yytext+2,NULL,16);return TOK_STR_FILLER;}
<STRING>"\""	{
	yylval.str = calloc(iwf$$commandline$$stringbuffer$length() + 1,sizeof(char));
	strcpy(yylval.str,iwf$$commandline$$stringbuffer$c_str());
	iwf$$commandline$$garbage$insert(yylval.str);
	return TOK_STR;
	}
<STRING>[.]	{yystringbuffer$push_back(yytext[0]);return TOK_STR_FILLER;}
