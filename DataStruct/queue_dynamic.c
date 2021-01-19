#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO, *PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}FILA;

void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanho(FILA* f){
    PONT end = f->inicio;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirFila(FILA* f){
    PONT end = f->inicio;
    printf("Fila: \" ");
    while(end != NULL){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool inserirNaFila(FILA* f, REGISTRO reg){
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if(f->inicio==NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    return true;
}

bool exclusaoDaFila(FILA* f, REGISTRO* reg){
    if(f->inicio == NULL) return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL) f->fim = NULL;
    return true;
}

void reinicializarFila(FILA* f){
    PONT end = f->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main(){
    return 0;
}