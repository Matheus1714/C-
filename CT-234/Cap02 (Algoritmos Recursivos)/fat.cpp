#include <stdio.h>
#include <time.h>
#include <unistd.h>

int fatRecursive(int n){
    if(n == 0 || n == 1) return 1;
    return n * fatRecursive(n-1);
}

int fatIterative(int n){
    int f = 1;
    while (n>0){
        f *= n--;
    }
    return f;
}

double getTimeExeRecursive(int n){
    double timeTimeExe = 0.0;

    clock_t beginTime = clock();
    fatRecursive(n);
    clock_t endTime = clock();

    timeTimeExe += (double)(endTime - beginTime) / CLOCKS_PER_SEC;

    return timeTimeExe;
}

double getTimeExeIterative(int n){
    double timeTimeExe = 0.0;

    clock_t beginTime = clock();
    fatIterative(n);
    clock_t endTime = clock();

    timeTimeExe += (double)(endTime - beginTime) / CLOCKS_PER_SEC;

    return timeTimeExe;
}

int main(){
    int n = 500;

    int fatr = fatRecursive(n);
    int fati = fatIterative(n);

    double timeFatRecussive = getTimeExeRecursive(n);
    double timeFatIterative = getTimeExeIterative(n);

    printf("(Fatorial Recursivo) O fatorial de %d eh %d. O tempo de execucao foi de %f segundos.\n", n, fatr, timeFatRecussive);
    printf("(Fatorial Iterativo) O fatorial de %d eh %d. O tempo de execucao foi de %f segundos.\n", n, fati, timeFatIterative);
    return 0;
}