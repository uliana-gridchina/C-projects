#include <stdio.h>
#include <Windows.h>

typedef struct Record {
    char name[40];
    char work[20];
    char number[10];
    char date_birth[10];
    char group[20];
} record;


int main() {
    char *a = "asdfghj", *b = "wertyui";
    printf("%d", a==b);

    return 0;
}