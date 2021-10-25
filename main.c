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

/*void *sum(void *thread_id) {
    //hold pipeData
    char pipeData[100] ="";
    //read from pipe and store in pipeData
    read(port[0],pipeData,100);

    int X = strtol()


}*/

int main(int argc, const char * argv[]) {

    const pid_t parentId = getpid();

    const char* X = argv[1];
    const char* Y = argv[2];

    printf("parent (PID %d) receives X=%S, Y=%S from the user\n",parentId,X,Y);

    return 0;
}
