#include <stdio.h>
#include <math.h> //для значения бесконечность
#include <stdlib.h> //для создания динамического массива
//функция заполнения массива
void make_array(int n, double array[]) {
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &array[i]);
    }
}
//функция вывода массива на экран
void give_array(int n, double array[]) {
    for (int i = 0; i < n; i++) {
        printf("%g ", array[i]);
    }
    printf("\n");
}

int main() {
    int n; //количество элементов в массиве
    double *array; //указатель на массив
    printf("Enter the length of array:\n");
    scanf("%d", &n); //чтение с клавиатуры значения количества элементов
    if (n <= 0) { //проверка на некорректный ввод значения количества элементов
        printf("Invalid value for the number of array elements");
        return 0;
    }
    array = (double*)malloc(n * sizeof(double)); //выделение памяти под массив
    if (array == NULL) { //проверка выдилилась ли память под массив
        printf("No memory has been allocated for the array");
        return 0;
    }
    make_array(n, array); //вызов функции заполнения массива
    printf("The array you have entered:\n");
    give_array(n, array); //вызов функции вывода массива

    double amin = INFINITY, amax = -INFINITY; //минимальный и максимальный элемент массива
    int imin = INFINITY, imax = -INFINITY; //индекс первого максимального и последнего минимального элемента массива
    for (int i = 0; i < n; i++) {
        if (array[i] > amax) { //строгое неравенство, чтобы максимальный элемент был первый
            amax = array[i];
            imax = i;
        }
        if (array[i] <= amin) { //нестрогое неравенство чтобы минимальный элемент был последним
            amin = array[i];
            imin = i;
        }
    }
    int start, end; //задаем границы для удаления элементов
    if (imax > imin) {
        start = imin;
        end = imax;
    }
    else {
        start = imax;
        end = imin;
    }
    int count = 0;
    for (int i = end-1; i > start; i--) { //пробегаем массив с конца
        if (array[i] > 0) {
            for (int j = i; j < n; j++) {
                array[j] = array[j+1]; //удаляем элементы массива путем сдвига
            }
            count += 1;
        }
    }
    n = n - count;
    array = (double*)realloc(array, n * sizeof(double));
    printf("The resulting array:\n");
    give_array(n, array);
    free(array);
    return 0;
}