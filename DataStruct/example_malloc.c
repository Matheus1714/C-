#include <stdio.h>
#include <malloc.h>

int main(){
    int* y = (int*) malloc(sizeof(int));

    *y = 20;
    int z = sizeof(int); // 4 bytes
    printf("*y=%i Z=%i\n", *y, z);

    return 0;
}