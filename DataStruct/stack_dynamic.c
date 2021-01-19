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
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
}PILHA;

void inicializarPilha(PILHA* p){
    p->topo = NULL;
}

bool estaVazia(PILHA* p){
    if(p->topo == NULL) return true;
    return false;
}

int tamanhoPilha(PILHA* p){
    PONT end = p->topo;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}
 
void exibirPilha(PILHA* p){
    PONT end = p->topo;
    printf("Pilha: \" ");
    while(end != NULL){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool inserirElemPilha(PILHA* p, REGISTRO reg){ // PUSH
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool excluirElemPilha(PILHA* p, REGISTRO* reg){ // POP
    if(p->topo == NULL) return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

void reinicializarPilha(PILHA* p){
    PONT apagar;
    PONT posicao = p->topo;
    while(posicao != NULL){
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

int main(){
    return 0;
}