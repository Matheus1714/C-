#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct tempNo{
    float valor;
    int coluna;
    struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct{
    PONT* A;
    int linhas;
    int colunas;
}MATRIZ;

void inicializarMatriz(MATRIZ* m, int lin, int col){
    int i;
    m->linhas = lin;
    m->colunas = col;
    m->A = (PONT*)malloc(lin*sizeof(PONT));
    for(i=0;i<lin; i++) m->A[i] = NULL;
}

bool atribuiMatriz(MATRIZ* m, int lin, int col, float val){
    if( lin < 0 || lin >= m->linhas || 
        col < 0 || col >= m->colunas) return false;
    PONT ant = NULL;
    PONT atual = m->A[lin];
    while(atual != NULL && atual->coluna<col){
        ant = atual;
        atual = atual->prox;
    }
    if(atual != NULL && atual->coluna == col){
        if(val == 0){
            if(ant == NULL) m->A[lin] = atual->prox;
            else ant->prox = atual->prox;
            free(atual);
        }else atual->valor = val;
    }else{
        PONT novo = (PONT)malloc(sizeof(NO));
        novo->coluna = col;
        novo->valor = val;
        novo->prox = atual;
        if(ant == NULL) m->A[lin] = novo;
        else ant->prox = novo;
    }
    return true;
}

float valorMatriz(MATRIZ* m, int lin, int col){
    if( lin < 0 || lin >= m->linhas || 
        col < 0 || col >= m->colunas) return 0;
    PONT atual = m->A[lin];
    while(atual != NULL && atual->coluna < col) atual = atual->prox;
    if(atual != NULL && atual->coluna == col) return atual->valor;
    return 0;
}

int main(){
    return 0;
}