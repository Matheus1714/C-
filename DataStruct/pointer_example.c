#include <stdio.h>

int main(){
    int x = 25;
    int* y = &x; // y get x reference
    *y = 30; // change reference x and y
    printf("Valor atual de x %i\n", x);
    return 0;
}