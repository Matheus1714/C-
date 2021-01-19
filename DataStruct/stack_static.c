#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo;
}PILHA;

void inicializarPilha(PILHA* p){
    p->topo = -1;
}

int tamanhoPilha(PILHA* p){
    return p->topo + 1;
}

void exibirPilha(PILHA* p){
    printf("Pilha: \" ");
    int i;
    for(i = p->topo; i>=0; i--){
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg){ // PUSH
    if(p->topo >=MAX-1) return false;
    p->topo = p->topo + 1;
    p->A[p->topo] = reg;
    return true;
}

bool excluirElementoPilha(PILHA* p, REGISTRO* reg){ // POP
    if(p->topo == -1) return false;
    *reg = p->A[p->topo];
    p->topo = p->topo - 1;
    return true;
}

void reinicializarPilha(PILHA* p){
    p->topo = -1;
}

int main(){
    return 0;
}