#include "stdio.h"
#include <fcntl.h>

void main(){
    char line[1024] = {};
    read(0, line, 1024);
    int fhandle=open("Result.txt", O_WRONLY | O_CREAT | O_TRUNC);
    write(fhandle, line, 1024);
}
