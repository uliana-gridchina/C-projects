#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void answer(int vector[][200], int coef[40][200], int k_vec) {
    printf("Matrix:\n");
    for (int i = 1; i <= coef[0][1]; i += 1) {
        for (int j = 0; j < coef[0][0]; j += 1) {
            printf("%d ", coef[i][j]);
        }
        printf("\n");
    }
    int kol = 0, sum = 0, flag = 0, right = 0;
    for (int i = 0; i < k_vec; i += 1) {
        if (coef[0][0] == vector[i][0]) {
            int j;
            for (j = 0; j < coef[0][1]; j += 1) { //проверяем i вектор в матрице
                right = coef[j+1][coef[0][0]];
                for (int k = 0; k < coef[0][0]; k += 1) {
                    sum += coef[j+1][k] * vector[i][k+1];
                }
                if (right == sum) {
                    flag += 1;
                }
                sum = 0;
            }
            if (flag == coef[0][1]) {
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
        printf("File with coefficients is empty\n");
    }
    if (fB == NULL) {
        printf("File with vectors is empty\n");
    }

    char line[256];
    char seperate[] = " ";
    char *num_seper;
    int k = 1, c = 0;
    int coef[40][200];
    int vector[6][200];

    while(fgets(line, 256, fB) != NULL) {
        num_seper = strtok(line, seperate);
        while (num_seper != NULL) {
            vector[c][k] = atoi(num_seper);
            k += 1;
            num_seper = strtok(NULL, seperate);
        }
        vector[c][0] = k-1; //количество координат вектора
        c += 1;
        k = 1;
    }
    int k_vec = c;

    c = 1;
    k = 0;

    while(fgets(line, 256, fA) != NULL) {

        if (strcmp(line, "-") == 0) {
            coef[0][1] = c-1;
            answer(vector, coef, k_vec);
            memset(coef, 0, sizeof(coef));
            c = 1;
            k = 0;
            continue;
        }

        num_seper = strtok(line, seperate);
        while (num_seper != NULL) {
            coef[c][k] = atoi(num_seper);
            k += 1;
            num_seper = strtok(NULL, seperate);
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