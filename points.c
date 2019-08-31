#include <stdio.h>
#include <stdlib.h>
int main(){
    int *vet, n;
    printf("tamanho do vetor: ");
    scanf(" %d", &n);

    vet = calloc(n, sizeof(int));

    for(int i=0; i<n;i++, printf("%d\n", vet[i]));

    vet = (int*)realloc(vet, n*sizeof(int));
    printf("tamanho do vetor: ");
    scanf(" %d", &n);
    for(int i=0; i<n;i++, printf("%d\n", vet[i]));
    
    return 0;
}