#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "string.h"
// #include "windows.h"

void main(){
    FILE * f = fopen("output.txt", "r");
    int fhandle;
    fhandle=open(f, O_RDONLY);

}