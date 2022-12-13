#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "string.h"
// #include "windows.h"

void main(){
    FILE * f = fopen("output.txt", "w");
    char a[100] = {};
    fgets(a, 100, stdin);
    fputs(a, f);
    fclose(f);
}