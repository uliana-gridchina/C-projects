#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *fA = fopen("A.txt", "r"), *fB = fopen("B.txt", "r");
    int a = fgetc(fA), k = 0;
    int array[2][2] = {0};
    if (isdigit(a)) {
        int b = atoi(&a);
        printf("B:  %d\n", b);
    }
    int b = atoi(&a);
    printf("B:  %s\n", b);
    array[0][0] = 2;
    printf("%d\n", array[0][1]);
    //printf("k: %d", k);
    return 0;
}