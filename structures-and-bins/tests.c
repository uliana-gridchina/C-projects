#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

typedef struct in {
    int a;
    int b;
    char c[10];
} in;



int check(char *str) {
    int dig, length = strlen(str);
    for (int i = 0; i < length; i += 1) {
        if (isdigit(str[i])) continue;
        else return -1;
    }
    dig = atoi(str);
    return dig;
}

void stru(team* data) {
    FILE *f = fopen("d.bin", "ab");
    printf("%u %u %u", sizeof(data), sizeof(team), sizeof(data) / sizeof(team));
    size_t count = fwrite(&data, sizeof(team), sizeof(data) / sizeof(team), f);
    printf("%zu objects out of %d were uploaded to the file", count, sizeof(data) / sizeof(team));
}

int main() {

    in dig = {23, 56, "dfgh"};
    team a[3];
    int b;

    FILE *f = fopen("d.bin", "wb");



    fwrite(&database, sizeof(team), sizeof(database) / sizeof(*database), f);

    while ( b != 10) {
        printf("s:\n");
        scanf("%d", &b);

    }

    fclose(f);

    f = fopen("d.bin", "rb");
    in out;
    fread(&a, sizeof(team), sizeof(database) / sizeof(*database), f);
    printf("%s %d %d %s\n", a[0].fio, a[0].age, a[1].height, a[2].sport);

    printf("%s %d %d %s\n", database[0].fio, database[0].age, database[1].height, database[2].sport);
    fclose(f);

    //printf("%zu %zu %d", sizeof(database), sizeof(team), sizeof(database) / sizeof(*database));

    stru(a);

    return 0;
}