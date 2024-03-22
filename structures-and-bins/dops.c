#include <stdio.h>
#include <Windows.h>


typedef struct dat {
    char a[5];
    char b[10];
    int c;
    int d;
    char *e;
} person;

int check() {
    char s[20];
    int flag = 0, dt;
    while (1) {
        fgets(s, sizeof(s), stdin);
        for (int i = 0; i < strlen(s) - 1; i += 1) {
            if ((!isdigit(s[i])) && (s[i] != '.')) {

                flag += 1;
                break;
            }
        }
        if (flag == 0) {
            dt = atoi(s);
            break;
        }
        else {
            printf("Value must include only numbers. Try again:\n");
        }
        flag = 0;
    }
    return dt;
}

char *check2(char *s) {
    if ((s[strlen(s)-1] != '\n') && (s[strlen(s)-1] != '\0')) {
        fflush(stdin);
        printf("Size of string must be less than 30. Try again:\n");
        while (1) {
            fgets(s, 30, stdin);
            if ((s[strlen(s)-1] != '\n') && (s[strlen(s)-1] != '\0')) {
                fflush(stdin);
                printf("Size of string must be less than 30. Try again:\n");
            }
            else {
                return s;
            }
        }
    }
}

int add_in_file(size_t, FILE*);
int delete_from_file(size_t, FILE*);
void search_in_file(size_t, FILE*);
void edit_file(size_t, FILE*);
void get_file(size_t, FILE*);

int main() {
    person a;
    //printf("%llu %llu", sizeof(a), sizeof(a.a)+sizeof(a.b)+sizeof(a.c)+sizeof(a.d)+sizeof(a.e));

    FILE *file = fopen("d.bin", "w");
    file = fopen("d.bin", "r");

    return 0;

//    char str[30];
//    fgets(str, sizeof(str), stdin);
//    strncpy(str, check2(str), sizeof(check2(str)));
//    printf("%s", str);

//    person dt[1];
//    dt->c = check();
//    printf("%d", dt->c);

//    FILE *file = fopen("dop.bin", "w+b");
//    if (file == NULL) {
//        printf("flag!");
//        FILE *file = NULL;
//        file = fopen("dop.bin", "w+b");
//    }
//
//    person *n = NULL;
//
//    person dat[3] = { {"abc", "qwerty", 10}, {"xyz", "pov", 33}, {"cwcd", "er", 12} };
//
//    fseek(file, 0, SEEK_END);
//    int count = fwrite(&dat, sizeof(person), 3, file);
//
//    person dread[count];
//    fseek(file, 0, SEEK_SET);
//    fread(&dread, sizeof(person), count, file);
//
//    for (int i = 0; i < count; i += 1) {
//        printf("%s %s %d\n", dread[i].a, dread[i].b, dread[i].c);
//    }
//    printf("\n");
//
//    fseek(file, sizeof(person), SEEK_SET);
//    fwrite(&n, sizeof(person), 1, file);
//
//    person dr[count-1];
//    fseek(file, 0, SEEK_SET);
//    fread(&dread, sizeof(person), count-1, file);
//
//    for (int i = 0; i < count; i += 1) {
//        printf("%s%s%d\n", dread[i].a, dread[i].b, dread[i].c);
//    }
//    printf("\n");



//    int num_case, count = 0;
//    printf("Choose what type of action do you want to do:\n"
//           "1 - add data in the file\n"
//           "2 - delete data from the file\n"
//           "3 - search data in the file\n"
//           "4 - edite data in the file\n"
//           "5 - look at the whole the file\n"
//           "6 - end program\n"
//           "Enter the number of action:\n");
//    scanf("%d", &num_case);
//
//    switch (num_case) {
//        case 1:
//            count = add_in_file(count, file);
//            break;
//        case 2:
//            count = delete_from_file(count, file);
//            break;
//        case 3:
//            search_in_file(count, file);
//            break;
//        case 4:
//            edit_file(count, file);
//            break;
//        case 5:
//            get_file(count, file);
//            break;
//    }

//    return 0;
}

int add_in_file(size_t count, FILE* file) {
    person dat[2] = { {"abc", "qwerty", 10}, {"xyz", "pov", 33} };

    fseek(file, 0, SEEK_END);
    count += fwrite(&dat, sizeof(person), 2, file);

    fseek(file, sizeof(person), SEEK_SET);
    count += fwrite(&dat, sizeof(person), 2, file);

    person dread[count];
    fseek(file, 0, SEEK_SET);
    fread(&dread, sizeof(person), count, file);

    for (int i = 0; i < count; i += 1) {
        printf("%s %s %d\n", dread[i].a, dread[i].b, dread[i].c);
    }


    return count;
}

int delete_from_file(size_t count, FILE* file) {
    int line;
    printf("enter:\n");
    scanf("%d", &line);

}