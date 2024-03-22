#include <stdio.h>
#include <string.h>
#include <ctype.h> //isdigit
#include <stdlib.h> //atoi
#include <unistd.h> //ftruncate
#include "main.h" //подключение заголовочного файла

#define var 2

int add_in_file(size_t, FILE*); //функция добавления одной записи в файл
int delete_from_file(size_t, FILE*); //функция удаления одной записи из файла
void search_in_file(size_t, FILE*); //функция поиска по заданному параметру в файле
void edit_file(size_t, FILE*); //функция изменения параметра в файле
void get_file(size_t, FILE*); //функция вывода содержимого файла

int check1() { //проверка на корректный ввод чисел
    char s[max_size_str];
    int flag = 0, dt;
    while (1) {
        fgets(s, sizeof(s), stdin);
        if (s[0] == '-') { //проверка, что число неотрицательное
            printf("Value mast be grater than zero. Try again:\n");
            continue;
        }
        for (int i = 0; i < strlen(s) - 1; i += 1) { //цикл для проверки каждого символа на цифру
            if ((!isdigit(s[i])) && (s[i] != '.')) { //если символ цифра или точка, то ничего
                flag += 1; //иначе меняется флаг
                break;
            }
        }
        if (flag == 0) { //проверка флага: если 0, значит строка это число
            dt = atoi(s);
            if (dt == 0) { //если равно нулю, то меняется флаг
                printf("Value mast be grater than zero. Try again:\n");
                continue;
            }
            break;
        }
        else if (flag != 100) { //проверка на равенство нулю
            printf("Value must include only numbers. Try again:\n");
        }
        flag = 0; //обнуление флага
    }
    return dt; //возращаемое значение - значение возраста/роста/веса
}

int check_c(char* s) {
    for (int i = 0; i < (strlen(s)-1); i += 1) { //проверка на корректный ввод символов
        if( !isalnum(s[i]) && (s[i] != ' ') ){
            return 0;
        }
    }
    return 1;
}

char *check2(char *s) { //проверка на корректный ввод имени/спорта/звания
    if (((s[strlen(s)-1] != '\n') && (s[strlen(s)-1] != '\0')) || (!check_c(s))) { //перед "или" условие отвечает за корректную длину, после за корректные символы
        if (!check_c(s)) {
            printf("There must be only letters and numbers in the string. Try again:\n");
        }
        else {
            printf("Size of string must be less than 30. Try again:\n");
        }
        fflush(stdin); //очистка буфера
        while (1) {
            fgets(s, 30, stdin); //чтение новой (возможно правильной) строки
            if ((s[strlen(s)-1] != '\n') && (s[strlen(s)-1] != '\0')) { //проверка на количество символов
                fflush(stdin);
                printf("Size of string must be less than 30. Try again:\n");
            }
            else {
                if (check_c(s)) { //проверка на символы
                    s[strlen(s)-1] = '\0'; //если в конце строки \n заменится на \0
                    return s;
                }
                else {
                    printf("There must be only letters and numbers in the string. Try again:\n");
                }
            }
        }
    }
    else {
        s[strlen(s)-1] = '\0'; //если в конце строки \n заменится на \0
        return s;
    }
}

int main() {
    int num_case = 0; //переменная для выбора действия из меню
    size_t count = 0; //перемменная для количества данных в файле
    FILE *file = fopen("data2.bin", "w+b"); //создание указателя для файла и открытие файла для чтения и записи

#if var == 2 //если вариант ввода исходный данных с клавиатуры, то сразу добавляем их в файл
    fseek(file, 0, SEEK_END);
    size_t k = fwrite(&database, sizeof(team), sizeof(database) / sizeof(team), file); //увеличение количества данных на величину, успешно записанных в файл
    count += k;
    printf("%llu objects out of %llu were uploaded to the file\n", k, sizeof(database) / sizeof(team));
    printf("The amount of data in the file: %llu\n\n", count);
#endif

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
        fflush(stdin); //сброс данных из буфера

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
            case 6:
                break;
            default: //проверка на корректный ввод
                printf("The vakue must be from 1 to 6. Try again\n\n");
        }
    }

    printf("You have finished work!");
    fclose(file);
    return 0;
}

int add_in_file(size_t count, FILE* file) {
    team data[1];
    printf("Enter person's name and last name:\n");
    fgets(data->fio, sizeof(data->fio), stdin);
    strcpy(data->fio, check2(data->fio));
    printf("Enter person's age:\n");
    data->age = check1();
    printf("Enter person's height:\n");
    data->height = check1();
    printf("Enter person's weight:\n");
    data->weight = check1();
    printf("Enter person's sport:\n");
    fgets(data->sport, sizeof(data->sport), stdin);
    strcpy(data->sport, check2(data->sport));
    printf("Enter person's rank:\n");
    fgets(data->rank, sizeof(data->rank), stdin);
    strcpy(data->rank, check2(data->rank));
    printf("The result: %-30s | %-6d | %-6d | %-6d | %-30s | %s\n", data->fio, data->age, data->height, data->weight, data->sport, data->rank);

    fseek(file, 0, SEEK_END); //смещение каретки в конец
    size_t k = fwrite(&data, sizeof(team), 1, file); //запись данных в файл из структуры
    count += k; //увеличение счетчика количества данных
    printf("%llu objects out of %d were uploaded to the file\n", k, 1);
    printf("The amount of data in the file: %llu\n\n", count);

    return count;
}

int delete_from_file(size_t count, FILE* file) {
    if (count == 0) {
        printf("There is no data to delete\n\n");
        return count;
    }
    int num;
    get_file(count, file); //вывод данных для удобства
    printf("Choose the number of line which you want to delete:\n");
    scanf("%d", &num);


    team del[1];

    for (int i = num; i < count; i += 1) { //цикл, в котором данные смещаются на одну позицию в начало, тем самым удаляя нужные данные
        fseek(file, sizeof(team)*i, SEEK_SET);
        fread(&del, sizeof(team), 1, file);
        fseek(file, sizeof(team)*(i - 1), SEEK_SET);
        fwrite(&del, sizeof(team), 1, file);
    }

    count -= 1;
    ftruncate(fileno(file), sizeof(team)*count); //уменьшение размера файла

    return count;
}

void search_in_file(size_t count, FILE* file) {
    if (count == 0) {
        printf("There is no data to search\n\n");
        return;
    }
    int num, item_d, flag, flag2 = 0;
    char item_s[max_size_str];
    team line;

    printf("1 - name; 2 - age; 3 - height; 4 - weight; 5 - sport; 6 - rank\n");
    printf("Choose the number of field which you want to find:\n");
    scanf("%d", &num);
    fflush(stdin);
    printf("Enter the value:\n");

    if ( (num == 1) || (num == 5) || (num == 6) ) { //если выбор 1/5/6, то значение для поиска записываем в строку
        fgets(item_s, sizeof(item_s), stdin);
        item_s[strlen(item_s)-1] = '\0';
    }
    else { //если выбор 2/3/4, то значение для поиска это число, записываем в переменную
        item_d = check1();
    }

    printf("Matching:\n");
    for (int i = 0; i < count; i += 1) { //поиск совпадения по данным
        flag = 0;
        fseek(file, sizeof(team)*i, SEEK_SET); //смещение каретки на одну структуру
        fread(&line, sizeof(team), 1, file); //чтение одной структуры

        switch (num) {
            case 1:
                if (!strcmp(item_s, line.fio)) {
                    flag += 1; //флаг на совпадение
                }
                break;
            case 2:
                if (item_d == line.age) {
                    flag += 1;
                }
                break;
            case 3:
                if (item_d == line.height) {
                    flag += 1;
                }
                break;
            case 4:
                if (item_d == line.weight) {
                    flag += 1;
                }
                break;
            case 5:
                if (!strcmp(item_s, line.sport)) {
                    flag += 1;
                }
                break;
            case 6:
                if (!strcmp(item_s, line.rank)) {
                    flag += 1;
                }
                break;
        }
        if (flag != 0) { //вывод данных если совпадение было
            flag2 = 1;
            printf("%-30s | %-6d | %-6d | %-6d | %-30s | %s\n", line.fio, line.age, line.height, line.weight, line.sport, line.rank);
        }
    }
    if (flag2 == 0) { //если совпадений не было
        printf("There is no match\n");
    }
    printf("\n");
}

void edit_file(size_t count, FILE* file) {
    if (count == 0) {
        printf("There is no data to edit\n\n");
        return;
    }
    team line;
    int num_line, num_field;

    get_file(count, file); //вывод данных для удобства
    printf("Choose the number of line which you want to edit:\n");
    while (1) {
        num_line = check1(); //выбор строки
        int flag = 0;
        for (int i = 1; i <= count; i += 1) {
            if (num_line != i) {
                flag += 1;
                continue;
            } else {
                break;
            }
        }
        if (flag == count) {
            printf("Value must be from 1 to %llu. Try again:\n", count);
        }
        else {
            break;
        }
    }
    fseek(file, sizeof(team)*(num_line - 1), SEEK_SET); //перемещение картеки на место перед нужной строкой
    fread(&line, sizeof(team), 1, file); //чтение этой строки

    printf("1 - name; 2 - age; 3 - height; 4 - weught; 5 - sport; 6 - rank\n");
    printf("Choose the number of field which you want to edit:\n");
    while (1) {
        num_field = check1(); //выбор поля
        if ((num_field != 1) && (num_field != 2) && (num_field != 3) && (num_field != 4) && (num_field != 5) && (num_field != 6)) {
            printf("Value must be from 1 to 6. Try again:\n");
        }
        else {
            break;
        }
    }
    printf("Enter what you want to replace it with:\n");
    fflush(stdin);

    switch (num_field) {
        case 1:
            fgets(line.fio, sizeof(line.fio), stdin); //получение нового значения для поля
            line.fio[strlen(line.fio) - 1] = '\0';
            break;
        case 2:
            line.age = check1(); //получение нового значения для поля
            break;
        case 3:
            line.height = check1(); //получение нового значения для поля
            break;
        case 4:
            line.weight = check1(); //получение нового значения для поля
            break;
        case 5:
            fgets(line.sport, sizeof(line.sport), stdin); //получение нового значения для поля
            line.sport[strlen(line.sport) - 1] = '\0';
            break;
        case 6:
            fgets(line.rank, sizeof(line.rank), stdin); //получение нового значения для поля
            line.rank[strlen(line.rank) - 1] = '\0';
            break;
    }
    printf("The result: %-30s | %-6d | %-6d | %-6d | %-30s | %s\n\n", line.fio, line.age, line.height, line.weight, line.sport, line.rank); //вывод новой строки

    fseek(file, sizeof(team)*(num_line - 1), SEEK_SET); //перемещение каретки на место перед нужной строкой
    fwrite(&line, sizeof(team), 1, file);
}

void get_file(size_t count, FILE* file) {
    if (count == 0) {
        printf("There is no data in the file\n\n");
        return;
    }
    team data[count];
    fseek(file, 0, SEEK_SET); //перемещение каретки в начало
    fread(&data, sizeof(team), count, file); //чтение всего файла

    char p = '\0';
    printf("N  Name%26c | Age%3c | Height | Weight | Sport%25c | Rank\n\n", p, p, p);
    for (int i = 0; i < count; i += 1) { //построчный вывод
        printf("%d: %-30s | %-6d | %-6d | %-6d | %-30s | %s\n", i+1, data[i].fio, data[i].age, data[i].height, data[i].weight, data[i].sport, data[i].rank);
    }
    printf("\n");
}