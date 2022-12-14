#include "stdio.h"
#include <fcntl.h>

void main(){
    char line[1024] = {};

    int fhandle=open("Result.txt", O_RDONLY);
    int duplicate_fhandle = dup(fhandle);
    int new_fhandle = open("Result.txt", O_RDONLY);

    lseek(fhandle, 10, SEEK_SET);

    printf("%d\n",fhandle);
    printf("%d\n",duplicate_fhandle);
    printf("%d\n",new_fhandle);

    read(fhandle, line, 7);
    write(1, line, 7);
    printf("\n");

    read(duplicate_fhandle, line, 7);
    write(1, line, 7);
    printf("\n");

    read(new_fhandle, line, 7);
    write(1, line, 7);
    printf("\n");
}
