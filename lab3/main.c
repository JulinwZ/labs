#include <windows.h>
#include <stdio.h>
#include <process.h>

void SetPosition(int x,int y){
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
    char line[100];

    system("CLS");

    CONSOLE_SCREEN_BUFFER_INFO screen;

    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hout,FOREGROUND_GREEN); 

    HANDLE opening = CreateFile("text.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (GetLastError() == 2){
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen);
        SetPosition(screen.srWindow.Right / 2, screen.srWindow.Bottom / 2);
        printf("File is not exist!");
        printf("\nPress enter");
        ReadFile(hin, line, 100, NULL, NULL);
        system("CLS");
        SetPosition(0, 0);
        exit(1);
    }
    CloseHandle(opening);
    

    HANDLE fhandle = CreateFile("text.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (GetLastError() == 32){
        while(GetLastError() == 32){
            SetConsoleTextAttribute(hout,FOREGROUND_GREEN);
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen);
            SetPosition(screen.srWindow.Right / 2 - 6, screen.srWindow.Bottom / 2 - 1);
            printf("Unsuccessful opening");
            SetPosition(screen.srWindow.Right / 2 - 16, screen.srWindow.Bottom / 2 + 1);
            printf("because the file is in use by another program.\n");
            sleep(2);
            system("CLS");
            fhandle = CreateFile("text.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        }
        system("CLS");
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen);
        SetPosition(screen.srWindow.Right / 2 - 6, screen.srWindow.Bottom / 2 - 1);
        printf("Successful opening!\n");
        ReadFile(fhandle, line, 100, NULL, NULL);
        WriteFile(hout, line, 100, NULL, NULL);
        printf("\nPress enter");
        ReadFile(hin, line, 100, NULL, NULL);
        system("CLS");
        exit(1);
    }
    else{
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen);
        SetPosition(screen.srWindow.Right / 2 - 6, screen.srWindow.Bottom / 2 - 1);
        printf("Successful opening!\n");
        ReadFile(fhandle, line, 100, NULL, NULL);
        SetPosition(screen.srWindow.Right / 2 - strlen(line) / 2, screen.srWindow.Bottom / 2);
        WriteFile(hout, line, 100, NULL, NULL);
        printf("\nPress enter");
        ReadFile(hin, line, 100, NULL, NULL);
        system("CLS");
        exit(1);
    }
    
}