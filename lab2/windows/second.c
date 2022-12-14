#include "stdio.h"
#include <fcntl.h>
#include "windows.h"

void main(){
    char line[1024] = {};

    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

    HANDLE f = CreateFile("Result.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE duplicate_f;
    HANDLE new_f = CreateFile("Result.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    DuplicateHandle(GetCurrentProcess(), f, GetCurrentProcess(), &duplicate_f, 0, FALSE, DUPLICATE_SAME_ACCESS);

    SetFilePointer(f, 10, NULL, FILE_BEGIN);

    printf("First handle = %d\n",f);
    printf("Duplicated handle = %d\n", duplicate_f);
    printf("Second handle = %d\n", new_f);

    ReadFile(f, line, 7, NULL, NULL);
    WriteFile(hout, line, 7, NULL, NULL);
    printf("\n");

    ReadFile(duplicate_f, line, 7, NULL, NULL);
    WriteFile(hout, line, 7, NULL, NULL);
    printf("\n");

    ReadFile(new_f, line, 7, NULL, NULL);
    WriteFile(hout, line, 7, NULL, NULL);
    printf("\n");
}
