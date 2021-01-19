#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct no{
    TIPOCHAVE chave;
    struct no *primFilho;
    struct no *proxIrmao;
} NO;

typedef NO* PONT;

PONT criarNovoNo(TIPOCHAVE ch){
    PONT novo = (PONT)malloc(sizeof(NO));
    novo->primFilho = NULL;
    novo->proxIrmao = NULL;
    novo->chave = ch;
    return novo;
}

PONT inicializa(TIPOCHAVE ch){
    return criarNovoNo(ch);
}

PONT buscaChave(TIPOCHAVE ch, PONT raiz){
    if(raiz == NULL) return NULL;
    if(raiz->chave == ch) return raiz;
    PONT p = raiz->primFilho;
    while(p){
        PONT resp = buscaChave(ch, p);
        if(resp) return resp;
        p = p->proxIrmao;
    }
    return NULL;
}

bool insere(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai){
    PONT pai = buscaChave(chavePai, raiz);
    if(!pai) return false;
    PONT filho = criarNovoNo(novaChave);
    PONT p = pai->primFilho;
    if(!p) pai->primFilho = filho;
    else{
        while(p->proxIrmao) p = p->proxIrmao;
        p->proxIrmao = filho;
    }
    return true;
}

void exibirArvore(PONT raiz){
    if(raiz == NULL) return;
    printf("%d(", raiz->chave);
    PONT p = raiz->primFilho;
    while(p){
        exibirArvore(p);
        p = p->proxIrmao;
    }
    printf(")");
}



int main(){
    PONT r = inicializa(1);

    insere(r, 2, 1);
    insere(r, 3, 2);
    insere(r, 4, 2);
    insere(r, 5, 2);
    insere(r, 6, 1);
    insere(r, 7, 6);
    insere(r, 8, 6);
    insere(r, 9, 6);
    insere(r, 10, 6);
    insere(r, 11, 1);
    insere(r, 12, 11);

    PONT busca = buscaChave(6, r);
    printf("A chave encontrada e %d\n", busca->chave);

    exibirArvore(r);
    return 0;
}