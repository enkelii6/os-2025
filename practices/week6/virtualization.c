#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

double a;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s process_nickname\n", argv[0]);
        exit(1);
    }

    srand((int)time(NULL) + (int)getpid());
    a = rand();

    fprintf(stderr, "Process %s. Value of a is %lf and address of a is %p\n", 
            argv[1], a, &a);
            
    sleep(1);

    fprintf(stderr, "Process %s. Value of a is %lf and address of a is %p\n", 
            argv[1], a, &a);

    sleep(3);
    return 0;
}