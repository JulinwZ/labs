#include "stdio.h"
#include <fcntl.h>
#include "windows.h"

void main(){
    char line[1024] = {};

    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE f = CreateFile("Result.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, NULL, NULL);

    ReadFile(hin, line, 1024, NULL, NULL);
    WriteFile(f, line, 1024, NULL, NULL);
}
