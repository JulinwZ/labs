#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(){
    system("clear");
    char screen_right[100];
    char screen_bottom[100];

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    sprintf(screen_bottom,"\033[%dB", w.ws_row/2 - w.ws_row/10) ;
    write(1, screen_bottom, strlen(screen_bottom));
    

    struct flock lock={F_WRLCK, SEEK_SET, 0, 0};
    struct flock unlock={F_UNLCK, SEEK_SET, 0, 0};
    int a = open("Test.txt", O_RDWR , 0600);
    int len;
    char line[100];
    if (errno == ENOENT){
        sprintf(screen_right,"\033[%dC", w.ws_col/2 - w.ws_col/20) ;
        write(1, screen_right, strlen(screen_right));
        write(1, "\033[1;31mFile is not existing\n", strlen("\033[1;31mFile is not existing\n"));
        char line[100];
        write(1, "\033[1;35mPress enter...", strlen("\033[1;35mPress enter..."));
        read(0, line, 100);
        exit(1);
    }
    else{
        while (fcntl(a, F_SETLK, &lock) == -1){
            sprintf(screen_right,"\033[%dC", w.ws_col/2 - w.ws_col/20) ;
            write(1, screen_right, strlen(screen_right));
            write(1, "\033[1;31mRight now we can't lock this file\n", strlen("\033[1;31mRight now we can't lock this file\n"));
            sleep(2);
        }
        system("clear");system("clear");

        sprintf(screen_bottom,"\033[%dB", w.ws_row/2 - w.ws_row/10) ;
        write(1, screen_bottom, strlen(screen_bottom));

        fcntl(a, F_SETLK, &lock);

        sprintf(screen_right,"\033[%dC", w.ws_col/2 - w.ws_col/20) ;
        write(1, screen_right, strlen(screen_right));

        write(1, "\033[0;32mSuccessful locking\n", strlen("\033[0;32mSuccessful locking\n"));
        len = read(a, line, 100);
        write(1, "\033[0;33m\n", strlen("\033[0;33m\n"));

        sprintf(screen_right,"\033[%dC", w.ws_col/2 - strlen(line)/2) ;
        write(1, screen_right, strlen(screen_right));
        
        write(1, line, len);
        printf("\n");

        sprintf(screen_right,"\033[%dC", w.ws_col/2 - strlen("\nWait for 7 seconds for unlocking")/2) ;
        write(1, screen_right, strlen(screen_right));
        
        write(1, "Wait for 7 seconds for unlocking", strlen("\nWait for 7 seconds for unlocking"));
        sleep(7);
        fcntl(a, F_SETLK, &unlock);
        write(1, "\033[1;35m\nPress enter...\n", strlen("\033[1;35m\nPress enter..."));
        read(0, line, 100);
        exit(1);
    }
}