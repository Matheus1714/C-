#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_LENGTH 32

int arrayMax(int *A, int n){ 
    int currentMax = A[0]; // 1 atribuição e 1 indexação
    for(int i=1; i<n; i++){ // (1 atribuição, 1 teste, 1 incremento)
        if(A[i] > currentMax){ // 1 indexação e 1 teste
            currentMax = A[i]; // 1 atribuição e 1 indexação (no máximo),
        }
    }
    return currentMax; // 1 return
} // Total = 5 + 6 * (n-1) = 6n-1

int main(){
    int A[MAX_ARRAY_LENGTH] = {1, 2, 3, 22, 44, 12, 0, 3, 34, 12};
    int maxElement = arrayMax(A, 10);
    printf("O maior valor do array eh %d", maxElement);
    return 0;
}