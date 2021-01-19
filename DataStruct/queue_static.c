#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio;
    int nroElem;
}FILA;

void inicializarFila(FILA* f){
    f->inicio = 0;
    f->nroElem = 0;
}

int tamanhoFila(FILA* f){
    return f->nroElem;
}

void exibirFila(FILA* f){
    printf("Fila: \" ");
    int i = f->inicio;
    int temp;
    for(temp = 0; temp < f->nroElem; temp++){
        printf("%i ", f->A[i].chave);
        i = (i+1)%MAX;
    }

    printf("\"\n");
}

bool inserirElementoFila(FILA* f, REGISTRO reg){
    if(f->nroElem >= MAX) return false;
    int posicao = (f->inicio + f->nroElem) % MAX;
    f->A[posicao] = reg;
    f->nroElem++;
    return true;
}

bool excluirElementoFila(FILA* f, REGISTRO* reg){
    if(f->nroElem==0) return false;
    *reg = f->A[f->inicio];
    f->inicio = (f->inicio + 1)%MAX;
    f->nroElem--;
    return true;
}

void reinicializarFila(FILA* f){
    inicializarFila(f);
}

int main(){
    return 0;
}