#include <stdio.h>
#include <pthread.h>

char lbuk[ ]="abcdefghijklmnoprst";
pthread_t tid1, tid2, tid3;

void procthread1(void *arg){
    int pos, color;
    if ((int)arg == 1){
        pos = 20;
        color = 34;
    }
    if ((int)arg == 2){
        pos = 40;
        color = 32;
    }
    if ((int)arg == 3){
        pos = 60;
        color = 31;
    }
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    for (int k=0; k<20; k++){
        printf("\033[%d;%dH\033[1;%dm",k+1, pos, color);
        for (int j=0; j<(int)arg * 2; j++){
            printf("%c",lbuk[k]);
        }
        printf("\n"); usleep(1000000);
    }
}

void procthread2(void *arg){
    int pos, color;
    if ((int)arg == 1){
        pos = 20;
        color = 34;
    }
    if ((int)arg == 2){
        pos = 40;
        color = 32;
    }
    if ((int)arg == 3){
        pos = 60;
        color = 31;
    }
    for (int k=0; k<20; k++){
        printf("\033[%d;%dH\033[1;%dm",k+1, pos, color);
        for (int j=0; j<(int)arg * 2; j++){
            printf("%c",lbuk[k]);
        }
        printf("\n"); usleep(1000000);
    }
}

void procthread3(void *arg){
    int pos, color;
    if ((int)arg == 1){
        pos = 20;
        color = 34;
    }
    if ((int)arg == 2){
        pos = 40;
        color = 32;
    }
    if ((int)arg == 3){
        pos = 60;
        color = 31;
    }
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    for (int k=0; k<20; k++){
        if (k == 12){
            
            pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
            printf("\033[29;20H\033[1;37mEnable to cancel 3 thread");
        }
        printf("\033[%d;%dH\033[%dm",k+1, pos, color);

        for (int j=0; j<(int)arg * 2; j++){
            printf("%c",lbuk[k]);
        }

        printf("\n"); usleep(1000000);
    }
}

void main(){
    printf("\033[2J");

    pthread_create(&tid1, NULL, (void*) procthread1, (void*)1);
    pthread_create(&tid2, NULL, (void*) procthread2, (void*)2);
    pthread_create(&tid3, NULL, (void*) procthread3, (void*)3);
    
    for (int k = 0; k < 20; k++){
        int rc;

        printf("\033[%d,1H\033[1,37m",k+1);
        printf("%c\n",lbuk[k]);

        if (k == 5){
            printf("\033[25;20H\033[1;37mTry to stop 1 thread");
            pthread_cancel(tid1);
        }
        if (k == 10){
            printf("\033[27;20H\033[1;37mTry to stop 3 thread");
            pthread_cancel(tid3);
        }
        usleep(1000000);
    }
    getchar();
    printf("\033[0m");
}
