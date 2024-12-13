// wget.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib, "urlmon.lib")
#pragma comment (linker, "/ALIGN:512")
#pragma comment(linker, "/OPT:NOWIN98")
#pragma comment(linker, "/merge:.data=.text")
#pragma comment(linker, "/merge:.rdata=.text")

void main()
{
	int argc = 0;
	DWORD exitcode = 0;
	int run = 0;
	LPWSTR* argvw = CommandLineToArgvW(GetCommandLineW(),&argc);
	if(argc<3){
		printf("usage: wget url filepath\n");
		exitcode = 1;
	}else{
		int error = URLDownloadToFileW(NULL, argvw[1], argvw[2], 0, NULL);
		if (error != S_OK){
			printf("download error 0x%08x",error);
			exitcode = 2;
		}else if(argc==4){	
			
			//error = (int)ShellExecuteW(NULL,NULL,argvw[2],NULL,NULL,0);
			//if(error > 32){
			//	printf("run error 0x%08x",error);
			//	exitcode = 3;
			//}
		}
	}
	ExitProcess(exitcode);
}

