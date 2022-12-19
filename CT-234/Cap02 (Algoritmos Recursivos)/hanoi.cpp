#include <stdio.h>

void hanoi(int n, int org, int dest, int aux) {
    if (n == 1){
        printf("Mova de ", org, "para ", dest);
    }
    else {
        hanoi(n-1, org, aux, dest);
        printf("Mova de ", org, "para ", dest);
        hanoi(n-1, aux, dest, org);
    }
}

int main(){
    int n = 10;
    hanoi(n, 1, 7, 0);
    return 0;
}