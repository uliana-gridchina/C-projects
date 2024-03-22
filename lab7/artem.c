//  Дана строка, содержащая от 1 до 30 слов, в каждом из которых от 1 до 10 латинских
//  букв и / или цифр.Словом считается последовательность символов, заключенная в
//  круглые скобки.Напечатать все найденные в строке слова.
#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define W 31 //max number of words
#define L 11 //max length of word

char* find_end (char* str) {
    int k_open; //      кол-во '('
    int k_close;//             ')'

    k_open = 1; // уже одна ( есть
    k_close = 0;
    char* tmp = (char*)malloc(L * sizeof(char)); // временная переменная для нашего слова
    char* result = tmp; // указатель на начало выделенной памяти

    char last_char = '\0'; // мб и не надо

    int j; //счетчик для временного слова

    for (j = 0; j < L; j++) { //

        if (*str == '(')
        {
            k_open++;
        };

        if (*str == ')')
        {
            k_close++;

            if (k_open == k_close) {
                tmp[j] = last_char;
                puts(tmp);
                return(result);
            }
        };

        tmp[j] = *str;
        tmp[j + 1] = last_char;

        str++;

    }

    puts(tmp);
    return(result);
}


void getWords(char * words[W], char str[331]) { //заполнение массива
    char *dp;

    int  j = 0; // переменная, отвечающая за кол-во слов

    for (int i = 0; i < strlen(str); i++) {

        if (str[i] == '(') { // если встречаем '('
            dp = find_end(&str[i+1]);
            words[j] = find_end(&str[i+1]);  // копируем в j-ое слово нашего массива слово из функции Find_end. Передаем find_end номер (i+1), тк на i-ом месте - СКОБКА,
            //    а дальше - символы нужного нам слова. ну и строку передаем туда
            j+=1; // увеличили кол-во слов
            //printf("%d\n", j);
        }
    }

    for (int i = 0; i < j; i++) {
        printf("Word #%d: \t", i + 1);
        puts(words[i]);
        printf(" ");
    }
}


void print_found_words(char **words, int num_Words) {

    for (int i = 0; i < num_Words; i++) {
        //printf("Word #%d: \t", i + 1);
        puts(words[i]);
        printf("\n");
    }

}

int main() {

    printf("Lab#7\t 16var\t Malyshev A.\n");

    printf("\nEnter from 1 to 10 words, each of which contains from 1 to 10 Latin letters and/or numbers in staples:\n\n");

    char str[331]; // L * (W - 1) + 1

    gets(str);
    puts("Your string:");
    puts(str);

    char * words[W]; // массив наших слов

    for (int j = 0; j <= W; j++) {
        words[j] = (char*)(malloc(11));
    }

    getWords(words, str);

    //print_found_words(words, num_Words);
    puts(str);

    for (int j = 0; j <= W; j++) {
        free(words[j]);
    }

    return 0;

}