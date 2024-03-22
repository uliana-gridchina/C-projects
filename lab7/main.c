#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_size_of_string 10000

char *processing(char str[]) {
    char sep[] = "."; //создание строки, по которой будет разделение
    char *sepstr;
    sepstr = strtok(str, sep); //разделение строки по точке

    char seperate[] = " "; //создание строки, по которой будет разделение
    char *seperstr;
    seperstr = strtok(sepstr, seperate);

    int k = 0; //счетчик количества слов
    char *array[30]; //создание массива, элементами которого будут вводимые слова

    //цикл для работы с strtok
    while (seperstr != NULL) {

        if ( k == 30) { //проверка на максимальное количество слов
            printf("The number of words must be less than 30");
            return 0;
        }

        size_t l = strlen(seperstr);
        if ( l > 10 ) {
            printf("The word length should be no more than 10 symbols");
            return 0;
        }

        array[k] = seperstr; //присваивания элементу массива слова из строки
        k += 1; //изменение счетчика
        seperstr = strtok(NULL, seperate);
    }

    if ( k == 0 ) { //проверка на наличие слов в строке
        printf("There is no word in the string");
        return 0;
    }

    int flag = 0; //подсчет количества выведенных элементов
    //цикл для вывода первого вхождения буквы в слове
    for (int i = 0; i < k-1; i += 1) {
        if ( strcmp(array[i], array[k-1]) != 0 ) { //проверка, что слово не совпадает с последним
            char newstr[] = ""; //строка, в которую будут добавляться первые вхождения буквы
            size_t lenght = strlen(array[i]); //определение длины слова
            for (int j = 0; j < lenght; j += 1) {
                if (strchr(newstr, array[i][j]) == NULL) { //проверка, что в newstr нет j-ой буквы из вводимого слова
                    strncat(newstr, &array[i][j], 1); //добавление в newstr буквы
                }
            }
            flag += 1;
            printf("%s ", newstr);
        }
    }
    if ( (flag == 0) && (k != 0) ) { //если ни одного слова не выведено, значит они совпадают с последним
        printf("All words in string match the last one");
    }
}

int main() {

    char str[max_size_of_string] = " "; //создание строки, в которую положится исходная строка
    printf("Enter your line:\n");
    fgets(str, sizeof(str), stdin); //получение строки с консоли

    if (str[0] == '.') { //проверка на наличие слов в строке
        printf("There is no word in the string");
        return 0;
    }

    char dot[] = ".";
    if (strpbrk(str, dot) == NULL) { //проверка на наличие точки в конце строки
        printf("There must be a dot in the end of the string");
        return 0;
    }

    size_t l = strlen(str);
    for (int i = 0; i < (l-1); i += 1) { //проверка на корректный ввод
        if( !isalnum(str[i]) && (str[i] != ' ') ){
            printf("There must be only letters and numbers in the string");
            return 0;
        }
        if (str[i+1] == '.') { //если следующий символ точка, не продолжать проверку
            break;
        }
    }

    processing(str);

    return 0;
}
