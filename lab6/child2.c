#include <stdio.h>
#include <windows.h>
int main(int argc, char** argv){

    char* buf;
    sprintf(buf, "%s %s", argv[0], "vnuk_child2");

    DWORD rc;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    memset(&si, 0, sizeof(STARTUPINFO));
    
    si.cb=sizeof(si);

    rc=CreateProcess("vnuk_child2.exe", buf, NULL, NULL, FALSE,
    NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);

    if (!rc){
        printf("Error create vnuk_Process1, codeError = %ld\n", GetLastError());
        getchar(); 
        return 0; 
    }

    for (int k=0; k<15; k++){
        printf("I am %s ... (k=%d)\n\r", argv[0], k); 
        Sleep(1000); 
    }

    CloseHandle(pi.hProcess); 
    CloseHandle(pi.hThread);

    getchar(); 
    return 0;
}