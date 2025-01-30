#include <stdio.h>
#include <time.h>

void fun(void) {
    printf("fun() starts\n");
    printf("Press enter to stop fun\n");
    
    while (1) {
        if (getchar())
            break;
    }
    
    printf("fun() ends\n");
}

int main(void) {
    clock_t start_time = clock();
    
    fun();
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("fun() took %.2f seconds to execute\n", time_taken);
    
    return 0;
}
