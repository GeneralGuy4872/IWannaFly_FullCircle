#define _____BUMPER(F,L) fprintf(stderr,"fall-through at\n%s\n%i\n",F,L);raise(SIGSEGV)

enum iwf::cli::tokentype {
	TOKTYP_SYNTAX,
	TOKTYP_INT,
	TOKTYP_LONG,
	TOKTYP_FLOAT,
	TOKTYP_STRING,
	TOKTYP_IDENT
	}

std::vector<std::vector<std::pair<iwf::cli::tokentype;std::any>>> lexer (std::string input) {
	std::vector<std::vector<std::pair<iwf::cli::tokentype;std::any>>> output;
	std::string buffer;
	int prebuffer;
	unsigned long n;
	unsigned long oline;

/** a case for spaghetti
 * this is a finite-state automata. each goto label is a MUTUALLY recursive
 * function invoked by a jmp call. each of these "functions" is useless
 * outside of the parent function's context. together, they form a lexer
 * whose behavior is altered by the input.
 *
 * if actual functions were used, there would exist pathological inputs
 * that could overflow the stack pointer; this would be a Bad Thing.
 *
 * the BUMPER macro indicates a point that execution SHOULD never reach;
 * the compiler will not necissarily recognise that the code is unreachable.
 * if a BUMPER somehow is reached, an appropriate error is printed, and
 * SIGSEGV is raised.
 */

/***ABANDON ALL HOPE, YE WHO ENTER HERE***/

MODE_INITIAL:
	prebuffer = input[n];
	if (isprint(prebuffer)) {
		if (isalnum(prebuffer)) {
			if (isdigit(prebuffer)) {
				goto ACTION_NUMBER;
			} else {
				goto ACTION_IDENT;
				}
		} else switch (prebuffer) {
			case '!' : goto ACTION_SYNTAX;
			case '"' : goto ACTION_STRING;
			case '#' : goto ACTION_LONG;
			case '$' : goto ACTION_HEX;
			//case '%' :
			//case '&' :
			//case '\'' :
			case '(' : goto ACTION_SYNTAX;
			case ')' : goto ACTION_SYNTAX;
			//case '*' :
			case '+' : goto ACTION_NUMBER_EXTRA;
			case ',' : goto ACTION_SYNTAX;
			case '-' : goto ACTION_NUMBER;
			case '.' : goto ACTION_REAL_START;
			//case '/' :
			//case ':' :
			case ';' :
			case '<' : goto ACTION_ASSIGN;
			//case '=' :
			//case '>' :
			//case '?' :
			case '@' : goto ACTION_OCTAL;
			case '[' : goto ACTION_SYNTAX;
			//case '\\' :
			case ']' : goto ACTION_SYNTAX;
			//case '^' :
			case '_' : goto ACTION_IDENT;
			//case '`' :
			case '{' :
			//case '|' :
			case '}' :
			//case '~' :
			default : goto ACTION_UNEXPECTED;
			}
	} else if (isspace(prebuffer) || ((034 <= prebuffer) && (prebuffer <= 037)) {
		goto ACTION_WHITESPACE;
	} else {
		goto ACTION_UNEXPECTED;
		}
  _____BUMPER(__FILE__,__LINE__);

ACTION_NUMBER:
	buffer = "";
	buffer.push_back(prebuffer);
		{
		std::pair<iwf::cli::tokentype;std::any> tmp;
		tmp.first = TOKTYP_INT;
		output[outputline].pushback(tmp);
		}
	readchar++;

  _____BUMPER(__FILE__,__LINE__);

ACTION_WHITESPACE:
	readchar++;
	goto MODE_INITIAL;
  _____BUMPER(__FILE__,__LINE__);

ACTION_IDENT:
	buffer = "";
	buffer.push_back(prebuffer);
	readchar++;
	goto MODE_IDENT;
  _____BUMPER(__FILE__,__LINE__);

ACTION_INITIAL_OCTAL:
	buffer = "";
	readchar++;
	goto MODE_OCTAL;
  _____BUMPER(__FILE__,__LINE__);
ACTION_INITIAL_HEX:
ACTION_INITIAL_INT:
	buffer = "";
	buffer.push_back(prebuffer);
		{
		std::pair<iwf::cli::tokentype;std::any> tmp;
		tmp.first = TOKTYP_INT;
		output[outputline].pushback(tmp);
		}
	readchar++;
	goto MODE_INT;
  _____BUMPER(__FILE__,__LINE__);

MODE_IDENT:
MODE_OCTAL:
MODE_HEX:
MODE_INT:
MODE_FLOAT:

ACTION_GOOD_RETURN:
	errno = 0;
	return output;
  _____BUMPER(__FILE__,__LINE__);

ACTION_BAD_RETURN:
	errno = ECANCELED;
	return output;
  _____BUMPER(__FILE__,__LINE__);
}
