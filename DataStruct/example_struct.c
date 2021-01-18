#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int peso; 
    int altura;
}PesoAltura;

#define alturaMaxima 225

int main(){
    PesoAltura* pessoa1=(PesoAltura*)malloc(sizeof(PesoAltura));

    pessoa1->peso = 80;
    pessoa1->altura =185;

    printf("Peso %i, Altura %i. \n", pessoa1->peso, pessoa1->altura);
    if(pessoa1->altura < alturaMaxima) printf("Altura menor que a altura máxima.\n");
    else printf("Altura maior que altura maxima.\n");

    return 0;
}
