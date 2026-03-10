#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 //To compile: gcc montecarlo-pi.c -o montecarlo-pi
//Usage: ./montecarlo-pi
int main(int argc, char* argv[]) {
double x,y,z;
int count = 0;
time_t started = time(NULL);
srand(started);
int n = (int) rand() % 10000 + 1; // Number of iterations
printf("Compiled on %s at %s\n",__DATE__,__TIME__);
printf("Execution started on %s",ctime(&started));
for (int i = 0; i < n; i++) {
x = (double) rand() / RAND_MAX;
y = (double) rand() / RAND_MAX;
z = x * x + y * y;
if (z <= 1) count++;
}
printf("The approximation of Pi using %d iterations is %f \n", n, (count / (double) n) * 4);
time_t stopped = time(0);
printf("Execution stopped on %s",ctime(&stopped));
return(0);
}
