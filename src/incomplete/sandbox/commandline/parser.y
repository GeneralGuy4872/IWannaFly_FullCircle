%token TOK_STR_FILLER

%union{
long l;
double f;
char * str;
%}

%token <str> TOK_IDENT TOK_STRING
%token <l> TOK_NUM
%token <f> TOK_FLOAT

str_filler	:	TOK_STR_FILLER
		|	str_filler str_filler
		;
