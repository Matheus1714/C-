#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubble(char *, int);

int main(){
    char s[80];

    printf("Digite uma string: ");
    gets(s);
    bubble(s,strlen(s));
    printf("A string ordenada é: %s.\n", s);

    return 0;
}

void bubble(char * item, int count){
    register int a,b;
    register char t;

    for(a=1;a<count;++a){
        for(b=count-1;b>=a;--b){
            if(item[b-1] > item[b]){
                t = item[b-1];
                item[b-1] = item[b];
                item[b] = t;
            }
        }
    }
}
