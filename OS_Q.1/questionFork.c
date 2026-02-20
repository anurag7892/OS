#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int arr[30];
    int status;
    pid_t p1, p2;
    int sum1 = 0, sum2 = 0;
    int i;

    srand(time(NULL));
    printf("Array:\n");
    for (i = 0; i < 30; i++) {
        arr[i] = rand() % 50 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");


    p1 = fork();
    if (p1 == 0) {
        int s = 0;
        for (i = 0; i < 15; i++) {
            if (arr[i] % 2 == 0)
                s += arr[i];
        }
        exit(s % 256);  
    }


    p2 = fork();
    if (p2 == 0) {
        int s = 0;
        for (i = 15; i < 30; i++) {
            if (arr[i] % 2 == 0)
                s += arr[i];
        }
        exit(s % 256);
    }

    
    waitpid(p1, &status, 0);
    sum1 = WEXITSTATUS(status);

    waitpid(p2, &status, 0);
    sum2 = WEXITSTATUS(status);

    printf("Even sum left side = %d\n", sum1);
    printf("Even sum right side = %d\n", sum2);

    return 0;
}



