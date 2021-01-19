#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct aux{
    TIPOCHAVE chave;
    struct aux *esq;
    struct aux *dir;
    int h;
}NO, *PONT;

PONT criaNo(TIPOCHAVE ch){
    PONT novoNo = (PONT) malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->h = 0;
    return novoNo;
}

PONT inicializa(){
    return NULL;
}

int maxValor(int a, int b){
    if(a > b) return a;
    return b;
}

int altura(PONT raiz){
    if(!raiz) return -1;
    return raiz->h;
}

PONT direita(PONT r){
    PONT aux;
    aux = r->esq;
    r->esq = aux->dir;
    aux->dir = r;
    r->h = maxvalor(altura(r->dir), altura(r->esq)) + 1;
    aux->h = maxValor(altura(aux->esq), r->h) + 1;
    return aux;
}

PONT esquerda(PONT r){
    PONT aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;
    r->h = maxvalor(altura(r->dir), altura(r->esq)) + 1;
    aux->h = maxValor(altura(aux->dir), r->h) + 1;
    return aux;
}



PONT esquerdaDireita(PONT r){
    r->esq = esquerda(r->esq);
    return direita(r);
}

PONT direitaEsquerda(PONT r){
    r->dir = direita(r->dir);
    return esquerda(r);
}

PONT insere(PONT raiz, TIPOCHAVE ch){
    if(!raiz) return criaNo(ch);
    if(ch < raiz->chave){
        raiz->esq = insere(raiz->esq, ch);
        if((altura(raiz->esq) - altura(raiz->dir)) == 2)
            if(ch < raiz->esq->chave) raiz = direita(raiz);
            else raiz = esquerdaDireita(raiz);
    }else{
        if(ch > raiz->chave){
            raiz->dir = insere(raiz->dir, ch);
            if((altura(raiz->dir) - altura(raiz->esq)) == 2)
                if(ch > raiz->dir->chave) raiz = esquerda(raiz);
                else raiz = direitaEsquerda(raiz);
        }
    }
    raiz->h = maxValor(altura(raiz->esq), altura(raiz->dir)) + 1;
    return raiz;
}

int main(){
    PONT r = inicializa();
    return 0;
}