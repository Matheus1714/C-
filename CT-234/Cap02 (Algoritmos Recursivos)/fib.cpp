#include <stdio.h>

int fibRecursive(int n){
    if(n == 0 || n == 1) return 1;
    return fibRecursive(n-1) + fibRecursive(n-2);
}

int fibIterative(int n){
    if(n == 0 || n == 1) return 1;
    int f1=1, f2=1, f3;
    for(int i=2; i<=n; i++){
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int main(){
    int n = 10;
    printf("(Fibonacci Recursivo) O fib(%d) eh %d\n", n, fibRecursive(n));
    printf("(Fibonacci Iterativo) O fib(%d) eh %d\n", n, fibIterative(n));
    return 0;
}