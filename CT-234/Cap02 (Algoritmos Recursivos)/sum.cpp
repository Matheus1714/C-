#include <stdio.h>

int sum(int n){
    if (n==1) return 1;
    return n + sum(n-1);
}

int sumWithStack(int n){
    printf("Estou em %d e vou para %d\n", n, n-1);
    if (n==1) return 1;
    return n + sumWithStack(n-1);
}

int main(){
    int n = 100;
    int s = sum(n);
    printf("A soma de todos os numeros de 0 ate %d eh %d\n", n, s);
    printf("Pilha de chamada da soma (%d).\n", n);
    sumWithStack(n);
    return 0;
}