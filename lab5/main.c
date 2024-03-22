#include <stdio.h>
#define row 10
#define column 10

int global_n, global_m;
//функция для создания и заполнения массива
void make_array(int n, int m, int array[][column]) {
    int i, j;
    printf("Enter the number of rows and columns for the matrix:\n");
    scanf("%d %d", &n, &m);
    if ( (n > 10) || (m > 10) || (n < 2) || (m < 2) ) { //проверка на некорректный ввод количества элементов
        global_n = -1;
        printf("You have entered the wrong values for the number of rows and columns");
        return;
    }
    global_n = n;
    global_m = m;
    for (i = 0; i < n; i++) { //заполнение массива
        printf("Enter the values for elements of the matrix in row %d:\n", i+1);
        for (j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}
//функция вывода массива
void give_array(int n, int m, int array[][column]) {
    printf("You have entered the matrix:\n");
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
//функция для обработки массива
int task(int n, int m, int array[][column]) {
    int k = 0, count = 0, sum_row = 0, sum = 0, i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum_row += array[i][j]; //сумма членов одной строки
            if (array[i][j] % 2 == 0) {
                k += 1; //количество четных элементов в строке
            }
        }
        if ((k == count) && (k != 0)){ //сравнение количества четных элементов с максимумом
            sum += sum_row; //если они равны, значит мы прибавляем к общей сумме сумму элементов строки, так как пока это максимум
        }
        if (k > count) { //если количество больше максимума делаем новый максимум и общую сумму равную сумме этой строки
            count = k;
            sum = sum_row;
        }
        k = 0; //обнуляем элементы, которые разные для каждой строки
        sum_row = 0;
    }
    if (sum == 0) {
        return 0;
    }
    else {
        return sum;
    }
}

int main() {
    int n, m, array[row][column];
    make_array(n, m, array);
    if (global_n == -1) { //проверка был ли некорректный ввод
        return 0;
    }
    else {
        give_array(global_n, global_m, array);
        int answer = task(global_n, global_m, array);
        printf("The sum of the elements of those rows that contain the largest number of even elements is %d", answer);
    }
    return 0;
}
