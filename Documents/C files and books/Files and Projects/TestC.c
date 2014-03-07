#include<stdio.h>

/*
The question is..
How to run this source file in Linux Environment?
OBS.: In my case, using Linux Mint 16 (Petra) distribuition occurred an error in the first time that a tried to execute my C file:

fatal error: stdio.h: No such file or directory compilation terminated.

The resolution of this problem for me was really simple, just a command could fixed it. This command installs a new gcc package in my Linux Mint.

sudo apt-get install g++

Ok, after the problem solved, let's run the C file source!
In order to run the file, follow these steps...

1. You need to search the C file directory, use cd C_LOCAL_OF_THE_FILE.
2. After to locate the C file, use the command gcc C_FILE.c -o C_FILE.bin. In this stage the compilation is done, if some message appear, it is reffered by erros in C_FILE.c lines, if nothing happend after the command execution, it means that a file C_FILE.bin was successfully constructed without erros. 
3. In the preview step, as you can see, a new file was generated, the C_FILE.bin; in this step you just need to execute this file, to run the program.
Enter the command ./C_FILE.bin to execute the program.

So, that is it enjoy Linux!

About the author:
Júnior Barros, student of Computer Engineering at UFRGS, RS, Brazil.
2014.5.1 - 1:55 p.m.
*/

int main(){
	printf("\nLanguage C test running inside Linux environment\n\n");
	return 0;
}
