#include <stdio.h>
#include <windows.h>

int main(){
    HANDLE hJob = CreateJobObject(NULL, NULL);

    DWORD rc1;
    DWORD rc2;

    STARTUPINFO si1;
    STARTUPINFO si2;

    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;


    memset(&si1, 0, sizeof(STARTUPINFO));
    memset(&si2, 0, sizeof(STARTUPINFO)); 
    
    si1.cb=sizeof(si1);
    si2.cb=sizeof(si2);

    rc1=CreateProcess("child1.exe", "Child1", NULL, NULL, FALSE,
    NORMAL_PRIORITY_CLASS, NULL, NULL, &si1, &pi1);

    rc2=CreateProcess("child2.exe", "Child2", NULL, NULL, FALSE,
    NORMAL_PRIORITY_CLASS, NULL, NULL, &si2, &pi2);

    AssignProcessToJobObject(hJob, pi2.hProcess);

    if (!rc1){
        printf("Error create Process1, codeError = %ld\n", GetLastError());
        getchar(); 
        return 0; 
    }

    if (!rc2){
        printf("Error create Process2, codeError = %ld\n", GetLastError());
        getchar(); 
        return 0; 
    }

    for (int k = 0; k<15; k++){
        if (k == 7){
            TerminateProcess(pi1.hProcess, 20);
            printf("Terminating first Process\n");
        }
        if (k == 11){
            TerminateJobObject(hJob, 20);
            printf("Terminating secondProcess\n");
        }
        printf("I am Parent... (my K=%d)\n", k); 
        Sleep(1000); 
    }

    CloseHandle(pi1.hProcess); 
    CloseHandle(pi1.hThread);

    CloseHandle(pi2.hProcess); 
    CloseHandle(pi2.hThread);

    getchar(); 
    return 0;
}