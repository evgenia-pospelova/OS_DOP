
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define ERROR_CREATE_THREAD -11
#define SUCCESS               0

typedef struct someArgs_tag {
    int digit;
    int out;
} someArgs_t;

void* odd_or_even(void *args) {
    someArgs_t *arg = (someArgs_t*) args;

    if (arg->digit % 2 == 0) arg->out = 1;
    else arg->out = 0;

    //printf("thread arg.out = %d\n", arg->digit % 2);
    return SUCCESS;
}

int main() {
    pthread_t thread;
    int status;
    someArgs_t arg;

    arg.digit = 11;

    status = pthread_create(&thread, NULL, odd_or_even, (void*) &arg);
    pthread_join(thread, NULL);

    if (status != 0) {
        printf("Ошибка! Нельзя создать поток, статус = %d\n", status);
        exit(ERROR_CREATE_THREAD);
    }

    printf("thread arg.out = %d\n", arg.out);
    return 0;
}
