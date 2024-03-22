#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void answer(int vector[][200], int coef[40][200], int k_vec) {
    printf("Matrix:\n"); //вывод текущей матрицы
    for (int i = 1; i <= coef[0][1]; i += 1) {
        for (int j = 0; j < coef[0][0]+1; j += 1) {
            printf("%d ", coef[i][j]);
        }
        printf("\n");
    }
    int kol = 0, sum = 0, flag = 0, right = 0;
    for (int i = 0; i < k_vec; i += 1) { //прогон по векторам
        if (coef[0][0] == vector[i][0]) {
            int j;
            for (j = 0; j < coef[0][1]; j += 1) { //проверяем i вектор в матрице
                right = coef[j+1][coef[0][0]];
                for (int k = 0; k < coef[0][0]; k += 1) {
                    sum += coef[j+1][k] * vector[i][k+1];
                }
                if (right == sum) { //проверяем что левая часть уравнения равна правой
                    flag += 1;
                }
                sum = 0;
            }
            if (flag == coef[0][1]) { //проверяем что количество верных уравнений равно их общему количеству
                printf("Correct vector for the sistem is:  ");
                for (int k = 0; k < k_vec+1; k += 1) {
                    printf("%d ", vector[i][k + 1]);
                }
                printf("\n");
                kol += 1;
            }
            flag = 0;
        }
    }
    if (kol == 0) {
        printf("There is no correct vector for the sistem");
    }
}

int main() {
    FILE *fA = fopen("A.txt", "r"), *fB = fopen("B.txt", "r");

    if (fA == NULL) {
        printf("File A with coefficients is empty\n");
        return 0;
    }
    if (fB == NULL) {
        printf("File with vectors is empty\n");
    }

    char line[256];
    char seperate[] = " ";
    char *num_seper;
    int k = 1, c = 0;
    int coef[40][200]; //массив для коэффициентов и свободных членов уравнений
    int vector[6][200]; //массив для координат векторов

    while(fgets(line, 256, fB) != NULL) {
        num_seper = strtok(line, seperate);
        while (num_seper != NULL) {
            if (isdigit(*num_seper)) { //проверка на корректный ввод
                vector[c][k] = atoi(num_seper); //преобразуем символ в число
                k += 1;
                num_seper = strtok(NULL, seperate);
            }
            else {
                printf("There must be only numbers");
                return 0;
            }
        }
        vector[c][0] = k-1; //количество координат вектора
        c += 1;
        k = 1;
    }
    int k_vec = c;

    c = 1;
    k = 0;

    while(fgets(line, 256, fA) != NULL) {
        char f = line[0];
        if (f == '-') { //окончание матрицы
            coef[0][1] = c-1;
            answer(vector, coef, k_vec);
            memset(coef, 0, sizeof(coef)); //обнуление массива
            c = 1;
            k = 0;
            continue;
        }

        num_seper = strtok(line, seperate);
        while (num_seper != NULL) {
            if (isdigit(*num_seper)) {
                coef[c][k] = atoi(num_seper);
                k += 1;
                num_seper = strtok(NULL, seperate);
            }
            else {
                printf("There must be only numbers");
                return 0;
            }
        }
        if ((coef[0][0] != k-1) && (coef[0][0] != 0)) {
            printf("Incorrect data entry: different rows of the matrix have different numbers of elements");
            return 0;
        }
        coef[0][0] = k-1; //количество коэффициентов при переменных в слау
        c += 1;
        k = 0;
    }

    fclose(fA);
    fclose(fB);
    return 0;
}