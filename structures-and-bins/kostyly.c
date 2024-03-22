#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "main.h"

#define var 2

#define max_count_of_people 20

int add_in_file(size_t, FILE*);
int delete_from_file(size_t, FILE*);
void search_in_file(size_t, FILE*);
void edit_file(size_t, FILE*);
void get_file(size_t, FILE*);

int check(char *str) {
    int dig, length = strlen(str);
    for (int i = 0; i < length; i += 1) {
        if (isdigit(str[i])) continue;
        else return -1;
    }
    dig = atoi(str);
    return dig;
}

int main() {
    int num_case = 0;
    size_t count = 0;
    FILE *file = fopen("data2.bin", "ab");
    fclose(file);

    while (num_case != 6) {
        printf("Choose what type of action do you want to do:\n"
               "1 - add data in the file\n"
               "2 - delete data from the file\n"
               "3 - search data in the file\n"
               "4 - edite data in the file\n"
               "5 - look at the whole the file\n"
               "6 - end program\n"
               "Enter the number of action:\n");
        scanf("%d", &num_case);

        switch (num_case) {
            case 1:
                count = add_in_file(count, file);
                break;
            case 2:
                count = delete_from_file(count, file);
                break;
            case 3:
                search_in_file(count, file);
                break;
            case 4:
                edit_file(count, file);
                break;
            case 5:
                get_file(count, file);
                break;
        }
    }

    printf("You have finished work!");
    file = fopen("data2.bin", "wb");
    fclose(file);
    return 0;
}

int add_in_file(size_t count, FILE* file) {
    file = fopen("data2.bin", "wb");
#if var == 1
    team data[1];
    printf("Enter person's name and last name:\n");
    fgets(data->fio, sizeof(data->fio), stdin);
    fgets(data->fio, sizeof(data->fio), stdin);
    data->fio[strlen(data->fio) - 1] = '\0';
    printf("Enter person's age:\n");
    scanf("%d", &data->age);
    printf("Enter person's height:\n");
    scanf("%d", &data->height);
    printf("Enter person's weight:\n");
    scanf("%d", &data->weight);
    printf("Enter person's sport:\n");
    fgets(data->sport, sizeof(data->sport), stdin);
    fgets(data->sport, sizeof(data->sport), stdin);
    data->sport[strlen(data->sport) - 1] = '\0';
    printf("Enter person's rank:\n");
    fgets(data->rank, sizeof(data->rank), stdin);
    data->rank[strlen(data->rank) - 1] = '\0';
    printf("%s %d %d %d %s %s\n", data->fio, data->age, data->height, data->weight, data->sport, data->rank);

    count += fwrite(&data, sizeof(team), 1, file);
    printf("%zu objects out of %d were uploaded to the filen\n", count, 1);
    printf("The amount of data in the file: %llu\n\n", count);
#elif var == 2
    count += fwrite(&database, sizeof(team), sizeof(database) / sizeof(team), file);
    printf("%llu objects out of %llu were uploaded to the file\n", count, sizeof(database) / sizeof(team));
    printf("The amount of data in the file: %llu\n\n", count);
#endif
    fclose(file);
    return count;
}

int delete_from_file(size_t count, FILE* file) {
    file = fopen("data2.bin", "rb");
    team data[count];
    int num;
    fread(&data, sizeof(team), count, file);
    fclose(file);

    get_file(count, file);
    printf("Choose the number of line which you want to delete:\n");
    scanf("%d", &num);
    for (int i = 0; i < count; i += 1) {
        if (i >= num) {
            strcpy(data[i-1].fio, data[i].fio);
            data[i-1].age = data[i].age;
            data[i-1].height = data[i].height;
            data[i-1].weight = data[i].weight;
            strcpy(data[i-1].sport, data[i].sport);
            strcpy(data[i-1].rank, data[i].rank);
        }
    }
    count -= 1;
    file = fopen("data2.bin", "wb");
    fwrite(&data, sizeof(team), count, file);
    fclose(file);
    printf("The amount of data in the file: %llu\n\n", count);
    return count;
}

void search_in_file(size_t count, FILE* file) {

}

void edit_file(size_t count, FILE* file) {
    file = fopen("data2.bin", "rb");
    team data[count];
    int num_line, num_field;
    fread(&data, sizeof(team), count, file);
    fclose(file);

    get_file(count, file);
    printf("Choose the number of line which you want to edit:\n");
    scanf("%d", &num_line);
    num_line -= 1;
    printf("1 - name; 2 - age; 3 - height; 4 - weught; 5 - sport; 6 - rank\n");
    printf("Choose the number of field which you want to edit:\n");
    scanf("%d", &num_field);
    printf("Enter what you want to replace it with:\n");

    switch (num_field) {
        case 1:
            fgets(data[num_line].fio, sizeof(data[num_line].fio), stdin);
            fgets(data[num_line].fio, sizeof(data[num_line].fio), stdin);
            data[num_line].fio[strlen(data[num_line].fio) - 1] = '\0';
            break;
        case 2:
            scanf("%d", &data[num_line].age);
            break;
        case 3:
            scanf("%d", &data[num_line].height);
            break;
        case 4:
            scanf("%d", &data[num_line].weight);
            break;
        case 5:
            fgets(data[num_line].sport, sizeof(data[num_line].sport), stdin);
            fgets(data[num_line].sport, sizeof(data[num_line].sport), stdin);
            data[num_line].sport[strlen(data[num_line].sport) - 1] = '\0';
            break;
        case 6:
            fgets(data[num_line].rank, sizeof(data[num_line].rank), stdin);
            fgets(data[num_line].rank, sizeof(data[num_line].rank), stdin);
            data[num_line].rank[strlen(data[num_line].rank) - 1] = '\0';
            break;
    }
    printf("The result: %s %d %d %d %s %s\n", data[num_line].fio, data[num_line].age, data[num_line].height, data[num_line].weight, data[num_line].sport, data[num_line].rank);

    file = fopen("data2.bin", "wb");
    fwrite(&data, sizeof(team), count, file);
    fclose(file);
}

void get_file(size_t count, FILE* file) {
    file = fopen("data2.bin", "rb");
    team data[count];
    fread(&data, sizeof(team), count, file);
    fclose(file);

    for (int i = 0; i < count; i += 1) {
        printf("%d: %s %d %d %d %s %s\n", i+1, data[i].fio, data[i].age, data[i].height, data[i].weight, data[i].sport, data[i].rank);
    }
    printf("\n");
}