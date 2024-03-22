#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dop_struct.h"

void swap_dig(int* a, int* b) { //функция, которая меняет местами числа
    int temp = *a;
    *a = *b;
    *b = temp;
}

void make_heap_dig(int array[], int n, int i) { //функция, которая проверяет какие числа нужно менять местами
    int parent = i;
    int left_child = i*2 + 1;
    int right_child = i*2 + 2;

    if ( (left_child < n) && (array[parent] < array[left_child]) ) parent = left_child;
    if ( (right_child < n) && (array[parent] < array[right_child]) ) parent = right_child;

    if (parent != i) { //если родитель оказался меньше потомка
        swap_dig(&array[parent], &array[i]);
        make_heap_dig(array, n, parent); //запускаем функцию еще раз, если мы были выше предпоследнего уровня в бинарном дереве
    }
}

void heap_sort_dig(int array[], int n) { //функция, которая осуществляет сортировку
    for (int i = n/2 - 1; i >= 0; i -= 1) { //делаем сортированное бинарное дерево
        make_heap_dig(array, n, i);
    }
    for (int i = n - 1; i > 0; i -= 1) { //меняем местами первый и последний элементы
        swap_dig(&array[0], &array[i]);
        make_heap_dig(array, i, 0); //заново делаем дерево сортированным
    }
}

void swap_ch(char** a, char** b) { //функция, которая меняет местами слова
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void make_heap_ch(char *array[], int n, int i) { //функция, которая проверяет какие слова нужно менять местами
    int parent = i;
    int left_child = i*2 + 1;
    int right_child = i*2 + 2;
    //strcmp() вернет число большее нуля, если первое слово "больше" второго, и меньше нуля, если наоборот
    if ( (left_child < n) && (strcmp(array[parent], array[left_child]) < 0) ) parent = left_child;
    if ( (right_child < n) && (strcmp(array[parent], array[right_child]) < 0) ) parent = right_child;

    if (parent != i) { //если родитель оказался меньше потомка
        swap_ch(&array[parent], &array[i]);
        make_heap_ch(array, n, parent); //запускаем функцию еще раз, если мы были выше предпоследнего уровня в бинарном дереве
    }
}

void heap_sort_ch(char *array[], int n) { //функция, которая осуществляет сортировку
    for (int i = n/2 - 1; i >= 0; i -= 1) { //делаем сортированное бинарное дерево
        make_heap_ch(array, n, i);
    }
    for (int i = n - 1; i > 0; i -= 1) { //меняем местами первый и последний элементы
        swap_ch(&array[0], &array[i]);
        make_heap_ch(array, i, 0); //заново делаем дерево сортированным
    }
}

int check(); //проверка корректного ввода номера поля для сортировки

int main() {
    int num_field;
    char *array_ch[8]; //массив для слов
    int array_dig[8]; //массив для чисел
    printf("1 - name; 2 - age; 3 - height; 4 - weight; 5 - sport; 6 - rank\n");
    printf("Enter the number of field to be sorted by:\n");
    num_field = check(); //номер варианта

    switch (num_field) {
        case 1: //в остальных случаях комментарии те же
            for (int i = 0; i < 8; i += 1) {
                array_ch[i] = database[i].fio; //заполняем массив, который будет проходить сортировку
            }
            heap_sort_ch(array_ch, 8); //сортируем массив
            for (int i = 0; i < 8; i += 1) { //вывод структуры
                if ( (i > 0) && (!strcmp(array_ch[i], array_ch[i-1])) ) { //случай если два одинаковых значения, предотвращет повторный вывод строк структуры, в которых одинаковые элементы
                    continue;
                }
                for (int j = 0; j < 8; j += 1) { //поиск нужной строки структуры
                    if (!strcmp(array_ch[i], database[j].fio)) { //сравнение элемента массива с элементом структуры
                        printf("%-30s | %-6d | %-6d | %-6d | %-30s | %s\n", database[j].fio, database[j].age, database[j].height, database[j].weight, database[j].sport, database[j].rank);
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < 8; i += 1) {
                array_dig[i] = database[i].age;
            }
            heap_sort_dig(array_dig, 8);
            for (int i = 0; i < 8; i += 1) {
                if ( (i > 0) && (array_dig[i] == array_dig[i-1]) ) {
                    continue;
                }
                for (int j = 0; j < 8; j += 1) {
                    if (array_dig[i] == database[j].age) {
                        printf("%-30s | %-6d | %-6d | %-6d | %-30s | %s\n", database[j].fio, database[j].age, database[j].height, database[j].weight, database[j].sport, database[j].rank);
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < 8; i += 1) {
                array_dig[i] = database[i].height;
            }
            heap_sort_dig(array_dig, 8);
            for (int i = 0; i < 8; i += 1) {
                if ( (i > 0) && (array_dig[i] == array_dig[i-1]) ) {
                    continue;
                }
                for (int j = 0; j < 8; j += 1) {
                    if (array_dig[i] == database[j].height) {
                        printf("%-30s | %-6d | %-6d | %-6d | %-30s | %s\n", database[j].fio, database[j].age, database[j].height, database[j].weight, database[j].sport, database[j].rank);
                    }
                }
            }
            break;
        case 4:
            for (int i = 0; i < 8; i += 1) {
                array_dig[i] = database[i].weight;
            }
            heap_sort_dig(array_dig, 8);
            for (int i = 0; i < 8; i += 1) {
                if ( (i > 0) && (array_dig[i] == array_dig[i-1]) ) {
                    continue;
                }
                for (int j = 0; j < 8; j += 1) {
                    if (array_dig[i] == database[j].weight) {
                        printf("%-30s | %-6d | %-6d | %-6d | %-30s | %s\n", database[j].fio, database[j].age, database[j].height, database[j].weight, database[j].sport, database[j].rank);
                    }
                }
            }
            break;
        case 5:
            for (int i = 0; i < 8; i += 1) {
                array_ch[i] = database[i].sport;
            }
            heap_sort_ch(array_ch, 8);
            for (int i = 0; i < 8; i += 1) {
                if ( (i > 0) && (!strcmp(array_ch[i], array_ch[i-1])) ) {
                    continue;
                }
                for (int j = 0; j < 8; j += 1) {
                    if (!strcmp(array_ch[i], database[j].sport)) {
                        printf("%-30s | %-6d | %-6d | %-6d | %-30s | %s\n", database[j].fio, database[j].age, database[j].height, database[j].weight, database[j].sport, database[j].rank);
                    }
                }
            }
            break;
        case 6:
            for (int i = 0; i < 8; i += 1) {
                array_ch[i] = database[i].rank;
            }
            heap_sort_ch(array_ch, 8);
            for (int i = 0; i < 8; i += 1) {
                if ( (i > 0) && (!strcmp(array_ch[i], array_ch[i-1])) ) {
                    continue;
                }
                for (int j = 0; j < 8; j += 1) {
                    if (!strcmp(array_ch[i], database[j].rank)) {
                        printf("%-30s | %-6d | %-6d | %-6d | %-30s | %s\n", database[j].fio, database[j].age, database[j].height, database[j].weight, database[j].sport, database[j].rank);
                    }
                }
            }
            break;
    }

    return 0;
}

int check() { //проверка на корректный ввод чисел
    char s[max_size_str];
    int flag = 0, dt;
    while (1) {
        fgets(s, sizeof(s), stdin);
        if (s[0] == '-') { //проверка, что число неотрицательное
            printf("Value must be from 1 to 6. Try again:\n");
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
            if ((dt != 1) && (dt != 2) && (dt != 3) && (dt != 4) && (dt != 5) && (dt != 6) || (dt == 0)) {
                printf("Value must be from 1 to 6. Try again:\n");
            }
            else {
                break;
            }
        }
        else {
            printf("Value must include only numbers. Try again:\n");
        }
        flag = 0; //обнуление флага
    }
    return dt; //возращаемое значение от 1 до 6
}