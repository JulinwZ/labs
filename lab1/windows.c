#include "stdio.h"
#include "windows.h"

int main(){
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE herr = GetStdHandle(STD_ERROR_HANDLE);
    printf("Handle input = %d\n",hin);
    printf("Handle output = %d\n",hout);
    printf("Handle error = %d\n",herr);

    char line[1024];
    printf("Write something: \n");

    ReadFile(hin, line, 100, NULL, NULL);

    printf("Readed: \n");
    WriteFile(hout, line, strlen(line), NULL, NULL);
}