#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    double x, y, z;
    int count = 0;
    time_t started = time(NULL);
    
    srand(42); 
    int n = 10000; 

    for (int i = 0; i < n; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1) count++;
    }

    printf("The approximation of Pi using %d iterations is %f \n", n, (count / (double) n) * 4);
    return 0;
}