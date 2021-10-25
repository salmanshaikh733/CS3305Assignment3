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
void *sum(void *thread_id) {
    //hold pipeData
    char pipeData[50] ="";
    //read from pipe and store in pipeData
    read(port[0],pipeData,50);

    //convert string to int for summation
    char* endPtr;
    int X = strtol(strtok(pipeData,","),&endPtr,10);
    int Y = strtol(strtok(NULL,""),&endPtr,10);

    printf("thread (TID 100) reads X=%d and Y=%d from the pipe\n",X,Y);

    // do summation
    int sum = X + Y;

    printf("thread (TID 100) writes X+Y = %d to the pipe\n",sum);

    //convert back into string
    char sumString[50]= "";
    sprintf(sumString,"%d",sum);
    //write to pipe
    write(port[1],sumString,50);

    return NULL;
}

void *odd_even(void *thread_id) {
    char pipeData[50]="";
    read(port[0],pipeData,50);

    char *ptr;
    int sum = strtol(pipeData,&ptr,10);

    printf("thread (TID 101) reads X+Y = %d from the pipe\n", sum);

    if(sum % 2 == 0) {
        printf("thread (TID 101) identifies X+Y = %d as an even number\n", sum);
    }else {
        printf("thread (TID 101) identifies X+Y = %d as an odd number\n", sum);
    }

    printf("thread (TID 101) writes X+Y = %d to the pipe\n",sum);

    char sumString[50]= "";
    sprintf(sumString,"%d",sum);
    //write to pipe
    write(port[1],sumString,50);

    return NULL;
}

void *digit_count(void *thread_id) {
    char pipeData[100] ="";
    read(port[0],pipeData,100);

    char *ptr;
    int sum = strtol(pipeData,&ptr,10);

    printf("thread (TID 102) reads X+Y= %d from the pipe\n",sum);

    int count = strlen(pipeData);

    printf("thread (TID 102) identifies X+Y =%d as a %d digit number\n",sum,count);

    return NULL;
}

int main(int argc, const char * argv[]) {

     char* X = argv[1];
     char* Y = argv[2];

    printf("parent (PID %d) receives X=%s and Y=%s from the user\n",getpid(),X,Y);

    //concat args to pipe data
    char pipeData[50] = "";
    strcat(pipeData,X);
    strcat(pipeData,",");
    strcat(pipeData,Y);

    pipe(port);

    //write to pipe
    printf("parent (PID %d) writes X=%s and Y=%s to the pipe\n",getpid(),X,Y);
    write(port[1],pipeData,50);

    //make threads
    pthread_t thread_1;
    pthread_t thread_2;
    pthread_t thread_3;

    pthread_create(&thread_1, NULL, &sum, NULL);
    pthread_join(thread_1, NULL);
    pthread_create(&thread_2, NULL, &odd_even, NULL);
    pthread_join(thread_2, NULL);
    pthread_create(&thread_3, NULL, &digit_count, NULL);
    pthread_join(thread_3, NULL);

    return 0;
}
