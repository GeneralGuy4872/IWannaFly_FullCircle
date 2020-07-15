#include <stdlib.h>
#include <stdio.h>


main (int argc,char *argv[]) {
	if (argc != 3) {
		fprintf(stderr,"usage:\nlistwrapper_codegen <outputfile.cc> <type name> <template argument>\n\nthis program emits wrappers for std::list objects;\nyou must provide it with the template argument.\n");
		exit(1);
		}
	FILE * outputfile; outputfile = fopen(argv[1],"w");

	fprintf(outputfile,"#ifndef __GG4872_LIST_%s__\n",argv[2]);
	fprintf(outputfile,"#define __GG4872_LIST_%s__\n",argv[2]);
	fprintf(outputfile,"\n");
	fprintf(outputfile,"#include \"cppkeywords.def\"\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"#ifdef __cplusplus\n");
	fprintf(outputfile,"extern \"C\" {\n");
	fprintf(outputfile,"#endif\n");
	fprintf(outputfile,"\n");
	fprintf(outputfile,"void list$$%s$$push_front (void * opaque,%s input);\n",argv[2],argv[3]);
	fprintf(outputfile,"void list$$%s$$push_back (void * opaque,%s input);\n",argv[2],argv[3]);
	fprintf(outputfile,"void list$$%s$$pop_front (void * opaque);\n",argv[2]);
	fprintf(outputfile,"void list$$%s$$pop_back (void * opaque);\n",argv[2]);
	fprintf(outputfile,"%s * list$$%s$$front (void * opaque);\n",argv[3],argv[2]);
	fprintf(outputfile,"%s * list$$%s$$back (void * opaque);\n",argv[3],argv[2]);
	fprintf(outputfile,"%s * list$$%s$$begin (void * opaque,size_t n);\n",argv[3],argv[2]);
	fprintf(outputfile,"%s * list$$%s$$rbegin (void * opaque,size_t n);\n",argv[3],argv[2]);
	fprintf(outputfile,"#ifdef __cplusplus\n");
	fprintf(outputfile,"}\n");
	fprintf(outputfile,"#endif\n");
	fprintf(outputfile,"#endif\n");
