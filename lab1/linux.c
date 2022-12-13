#include "stdio.h"
#include <fcntl.h>
#include <string.h>

int main(){
    char line[1024];
    int lenght;
    if (isatty(1)){
        if (isatty(0)){
            write(1, "Write something: \n", strlen("Write something: \n"));
            fgets(line, 1024, stdin);
            write(1, "Readed\n", strlen("Readed\n"));
            write(1 ,line, strlen(line));
        }
        else{
            fgets(line, 1024, stdin);
            write(1, "Readed\n", strlen("Readed\n"));
            write(1,line, strlen(line));
        }
    }
    else{
        if (isatty(0)){
            write(2,"Write something: \n",strlen("Write something: \n"));
            lenght=read(0,line,1024);
            write(1, "Readed\n", strlen("Readed\n"));
            write(1,line,lenght);
        }
        else{
            fgets(line, 1024, stdin);
            write(1,"Readed\n", strlen("Readed\n"));
            write(1,line, strlen(line));
        }
    }
}