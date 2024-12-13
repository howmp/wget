// wget.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib, "urlmon.lib")
#pragma comment (linker, "/ALIGN:512")
#pragma comment(linker, "/OPT:NOWIN98")
#pragma comment(linker, "/merge:.data=.text")
#pragma comment(linker, "/merge:.rdata=.text")
int __getmainargs(int *, char ***, char ***, int, void *);

void main()
{
	int argc = 0;
	int error = 0;
	char** argv = NULL;
	char** envp = NULL;
	__getmainargs(&argc,&argv,&envp,0,NULL);
	
	if(argc<3){
		// usage: wget url filepath
		printf(0x400000);
		exit(1);
	}
	error = URLDownloadToFileA(NULL, argv[1], argv[2], 0, NULL);
	if (error != S_OK){
		// download error 0x%08x
		printf(0x400000,error);
		exit(2);
	}
	//if(argc==4){	
			//error = (int)ShellExecuteW(NULL,NULL,argvw[2],NULL,NULL,0);
			//if(error > 32){
			//	printf("run error 0x%08x",error);
			//	exitcode = 3;
			//}
	//}
	exit(0);
}

