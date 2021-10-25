#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

/*
 * CS3305 - Assignment 3
 *
 * Created by Salman Shaikh on 2021-10-25
 * Student Number mshaik52 - 250959996
 */


int port[2];

int sharedResource = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *sum(void *thread_id) {
    //hold pipeData
    char pipeData[50] ="";
    //read from pipe and store in pipeData
    read(port[0],pipeData,50);

    //int X = strtol()


}

void *odd_even(void *thread_id) {

}

void *digit_count(void *thread_id) {

}

int main(int argc, const char * argv[]) {

    const pid_t parentId = getpid();

     char* X = argv[1];
     char* Y = argv[2];

    printf("parent (PID %d) receives X=%s and Y=%s from the user\n",parentId,X,Y);

    //concat args to pipe data
    char pipeData[50] = "";
    strcat(pipeData,X);
    strcat(pipeData,",");
    strcat(pipeData,Y);
    pipe(port);

    //write to pipe
    printf("parent (PID %d) writes X=%s and Y=%s to the pipe\n",parentId,X,Y);
    write(port[1],pipeData,50);

    //make threads
    pthread_t thread_1 =100;
    pthread_t thread_2 =101;
    pthread_t thread_3 =102;

    pthread_create(&thread_1, NULL, &sum, NULL);
    pthread_join(thread_1, NULL);

    pthread_create(&thread_2, NULL, &odd_even, NULL);
    pthread_join(thread_2, NULL);

    pthread_create(&thread_3, NULL, &digit_count, NULL);
    pthread_join(thread_3, NULL);

    return 0;
}
