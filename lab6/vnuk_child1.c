#include <stdio.h>
#include <windows.h>
int main(int argc, char** argv){
    for (int k=0; k<15; k++){
        printf("I am %s, my father %s ... (k=%d)\n", argv[1], argv[0], k); 
        Sleep(1000); 
    }
}