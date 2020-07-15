#include <stdlib.h>
#include <stdio.h>
#define newline puts("")

#define KEYTYPE_NOSPACE argv[1]
#define VALUETYPE_NOSPACE argv[2]
#define C_KEYTYPE argv[3]
#define C_VALUETYPE argv[4]

	main (int argc,char *argv[]) {
		if (argc < 6) {
			fprintf(stderr,"usage:\nmapwrapper_headergen <keytype nospace> <valuetype nospace> <C keytype> <C valuetype>( <%%top...>) > output.h\n");
			}

		if (argc >= 5) {
			for (int n = 5;n <= argc;n++) {
printf("%s\n",argv[n]);
				}
newline;		}

printf("typedef void * iwf$$datamap$%s$%s;\n",KEYTYPE_NOSPACE,VALUETYPE_NOSPACE);
newline;
printf("void iwf$$datamap$%s$%s$$insert (void * opaque,%s key,%s value);\n",KEYTYPE_NOSPACE,VALUETYPE_NOSPACE,C_KEYTYPE,C_VALUETYPE);
printf("%s iwf$$datamap$%s$%s$$safe_at (void * opaque,%s key);\n",C_VALUETYPE,KEYTYPE_NOSPACE,VALUETYPE_NOSPACE,C_KEYTYPE);
printf("void iwf$$datamap$%s$%s$$erase (void * opaque,%s key);\n",KEYTYPE_NOSPACE,VALUETYPE_NOSPACE,C_KEYTYPE);
