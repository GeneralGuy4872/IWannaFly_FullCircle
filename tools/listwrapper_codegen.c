#include <stdlib.h>
#include <stdio.h>

main (int argc,char *argv[]) {
	if ((argc != 3) && (argc != 4)) {
		fprintf(stderr,"usage:\nlistwrappergen_cc <outputfile.cc> <type name> <template argument>( <%%top>)\n\nthis program emits wrappers for std::list objects;\nyou must provide it with the template argument.\n");
		exit(1);
		}
	FILE * outputfile; outputfile = fopen(argv[1],"w");

	if (argc == 4) {
		fprintf(outputfile,"%s\n",argv[4]);
		fprintf(outputfile,"\n");
		};

	fprintf(outputfile,"#ifdef __cplusplus\n");
	fprintf(outputfile,"extern \"C\" {\n");
	fprintf(outputfile,"#endif\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"void list$$%s$$push_front (void * opaque,%s input) {\n",argv[2],argv[3]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\tobject->push_front(input);\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"void list$$%s$$push_back (void * opaque,%s input) {\n",argv[2],argv[3]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\tobject->push_back(input);\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"void list$$%s$$pop_front (void * opaque) {\n",argv[2]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\tobject->pop_front();\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"void list$$%s$$pop_back (void * opaque) {\n",argv[2]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\tobject->pop_back();\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"%s * list$$%s$$front (void * opaque) {\n",argv[3],argv[2]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\treturn &(object->front());\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"%s * list$$%s$$back (void * opaque) {\n",argv[3],argv[2]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\treturn &(object->back());\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"%s * list$$%s$$begin (void * opaque,size_t n) {\n",argv[3],argv[2]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\tif (n < object.size()) {\n");
	fprintf(outputfile,"\t\treturn &(*(object->begin() + n));\n");
	fprintf(outputfile,"\t\t}\n");
	fprintf(outputfile,"\terrno = EINVAL;\n");
	fprintf(outputfile,"\treturn NULL;\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"%s * list$$%s$$rbegin (void * opaque,size_t n) {\n",argv[3],argv[2]);
	fprintf(outputfile,"\tstd::list<%s> * object = opaque;\n",argv[3]);
	fprintf(outputfile,"\tif (n < object.size()) {\n");
	fprintf(outputfile,"\t\treturn &(*(object->rbegin() + n));\n");
	fprintf(outputfile,"\t\t}\n");
	fprintf(outputfile,"\terrno = EINVAL;\n");
	fprintf(outputfile,"\treturn NULL;\n");
	fprintf(outputfile,"\t};\n");
	fprintf(outputfile,"#ifdef __cplusplus\n");
	fprintf(outputfile,"}\n");
	fprintf(outputfile,"#endif\n");
	};
