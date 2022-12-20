#include "stdio.h"
#include "windows.h"

int main(){
    system("CLS");

    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE fhandle = CreateFile("text.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    char line[100];

    ReadFile(fhandle, line, 100, NULL, NULL);
    WriteFile(hout, line, strlen(line), NULL, NULL);

    char s;
    
    DWORD actlen = 0;

    INPUT_RECORD buffer;

    SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    buffer.EventType = MOUSE_EVENT;

    COORD info_coord, text_coord, pos;

    info_coord.Y = 15;
    info_coord.X = 1;
    text_coord.Y = 17;
    text_coord.X = 1;

    while(TRUE){
        if(ReadConsoleInput(hin, &buffer, 1, &actlen)){
            if(buffer.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED){
                exit(1);
            }

            if (buffer.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
                pos.X = buffer.Event.MouseEvent.dwMousePosition.X;
                pos.Y = buffer.Event.MouseEvent.dwMousePosition.Y;

                ReadConsoleOutputCharacter(hout, &s, 1, pos, &actlen);
            }

            if (s != ' '){
                SetConsoleCursorPosition(hout, info_coord);

                sprintf(line,"                     ");
                WriteFile(hout, line, strlen(line), NULL, NULL);

                SetConsoleCursorPosition(hout, info_coord);

                sprintf(line,"(x = %d; y = %d)", pos.X, pos.Y);
                WriteFile(hout, line,strlen(line), NULL, NULL);

                SetConsoleCursorPosition(hout, text_coord);

                ReadConsoleOutputCharacter(hout, &s, 1, pos, &actlen);
                WriteConsoleOutputCharacter(hout, &s, 1, text_coord, &actlen);
            }
        }
    }



}