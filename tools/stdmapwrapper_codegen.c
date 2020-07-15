#include <stdlib.h>
#include <stdio.h>
#define newline puts("")

#define KEYTYPE_NOSPACE argv[1]
#define VALUETYPE_NOSPACE argv[2]
#define C_KEYTYPE argv[3]
#define C_VALUETYPE argv[4]
#define KEYTYPE argv[5]
#define VALUETYPE argv[6]
#define CAST_C_KEYTYPE_INPUT argv[7]
#define CAST_C_VALUETYPE_INPUT argv[8]
#define CAST_C_RETURNTYPE_INPUT argv[9]
int CastCKeyType = 0;
int CastCValueType = 0;
int CastCReturnType = 0;
	main (int argc,char *argv[]) {
		if (argc < 7) {
			fprintf(stderr,"usage:\nmapwrapper_codegen <keytype nospace> <valuetype nospace> <C keytype> <C valuetype> <real keytype> <real valuetype> <cast C keytype?> <cast C valuetype?> <cast C returntype?>( <C keytype cast expression> <C valuetype cast expression> <C return cast expression> <%%top...>) > output.cc\n");
			return 1;
			}

		{
		int Top = 10;

		if (argc >= 8) {
			CastCKeyType = !!atoi(CAST_C_KEYTYPE_INPUT);
			if (CastCKeyType) {
				CastCKeyType = Top;
				Top++;
			}}

		if (argc >= 9) {
			CastCValueType = !!atoi(CAST_C_VALUETYPE_INPUT);
			if (CastCValueType) {
				CastCValueType = Top;
				Top++;
			}}

		if (argc >= 10) {
			CastCReturnType = !!atoi(CAST_C_RETURNTYPE_INPUT);
			if (CastCReturnType) {
				CastCReturnType = Top;
				Top++;
			}}

		if (argc > Top) {
			while (Top < argc) {
printf("%s\n",argv[Top]);
				Top++;
				}
newline;		}
		}

printf("void iwf$$datamap$%s$%s$$insert (void * opaque,%s key,%s value) {\n",KEYTYPE_NOSPACE,VALUETYPE_NOSPACE,C_KEYTYPE,C_VALUETYPE);
printf("\tstd::map<%s;%s> * object = opaque;\n",KEYTYPE,VALUETYPE);
printf("\tobject->operator[](%s(key)) = %s(value);\n", CastCKeyType ? argv[CastCKeyType] : "" , CastCValueType ? argv[CastCValueType] : "");
puts("\t}");
newline;
printf("%s iwf$$datamap$%s$%s$$safe_at (void * opaque,%s key) {\n",C_VALUETYPE,KEYTYPE_NOSPACE,VALUETYPE_NOSPACE,C_KEYTYPE);
printf("\tstd::map<%s;%s> * object = opaque;\n",KEYTYPE,VALUETYPE);
printf("\treturn %s(object->operator[](%s(key)));\n", CastCReturnType ? argv[CastCReturnType] : "" , CastCKeyType ? argv[CastCKeyType] : "");
puts("\t}");
newline;
printf("void iwf$$datamap$%s$%s$$erase (void * opaque,%s key) {\n",KEYTYPE_NOSPACE,VALUETYPE_NOSPACE,C_KEYTYPE);
printf("\tstd::map<%s;%s> * object = opaque;\n",KEYTYPE,VALUETYPE);
printf("\tobject->erase(%s(key));\n", CastCKeyType ? argv[CastCKeyType] : "");
puts("\t}");
	}
