#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void parse_command(char commands[],char *num[]){
    int i = 0;

    for(char* p=strtok(commands," ") ; p!=NULL ; p=strtok(NULL," "), i++)
        num[i] = p;

    num[i] = NULL;
}


int main(int argc, char *argv[]) { 
    char buf[BUFSIZ];
    char *myargs[3]; 
    while(1){
	write (1, "$ ", 2);
	(void) fgets(buf,sizeof(buf),stdin);

	int i;
        for(i=0; *(buf+i)!='\n';i++)
	    ;
        *(buf+i) = '\0';

        parse_command(buf, myargs);

	if (myargs[0] != NULL)
	    execvp(myargs[0], myargs);
    }
    return 0; 
}
