#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo1;
    int topo2;
}PILHADUPLA;

void inicializarPilhaDupla(PILHADUPLA* p){
    p->topo1 = -1;
    p->topo2 = MAX;
}

int tamanhoPilhaDupla(PILHADUPLA* p){
    return (p->topo1 + 1) + (MAX - p->topo2); 
}

bool exibirUmaPilha(PILHADUPLA* p, int pilha){
    if(pilha < 1 || pilha > 2) return false;
    print("Pilha %i: \" ", pilha);
    int i;
    if(pilha == 1) for (i=p->topo1;i>0; i--) printf("%i ", p->A[i].chave);
    if(pilha == 2) for (i=p->topo2; i<MAX; i++) printf("%i ", p->A[i].chave);
    printf("\"\n");
    return true;
}

bool inserirElementoPilha(PILHADUPLA* p, REGISTRO reg, int pilha){
    if(pilha<1 || pilha > 2) return false;
    if(p->topo1 + 1 == p->topo2) return false;
    if(pilha == 1){
        p->topo1 = p->topo1 + 1;
        p->A[p->topo1] = reg;
    }
    if(pilha == 2){
        p->topo2 = p->topo2 - 1;
        p->A[p->topo2] = reg;
    }
    return true;
}

bool excluirElementoPilha(PILHADUPLA* p, REGISTRO* reg, int pilha){
    if(pilha < 1 || pilha > 2) return false;
    if(pilha == 1){
        if(p->topo1 == -1) return false;
        *reg = p->A[p->topo1];
        p->topo1 = p->topo1 - 1;
    }
    if(pilha == 2){
        if(p->topo2 == MAX) return false;
        *reg = p->A[p->topo2];
        p->topo2 = p->topo2 + 1;
    }
    return true;
}

void reinicializarPilha(PILHADUPLA* p){
    p->topo1 = -1;
    p->topo2 = MAX;
}

int main(){
    return 0;
}