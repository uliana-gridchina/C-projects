#include <stdio.h>  //библиотека с output/input
#include <math.h>   //библиотека для математических функций

int main() {

    int x, y; //объявление переменных типа int
    float a, b, z; //объявление переменных типа float
    printf("Enter values for x, y and z: \n");
    scanf_s("%d %d %f", &x, &y, &z); //чтение значений, вводимых с клавиатуры

    printf("You entered this values: \nx = %10d\ny = %10d\nz = %10.5e\n", x, y, z); //форматный вывод значений x, y, z

    a = log( fabs( (y - sqrt(abs(x) ))*(x - y/(abs(x) + pow(x, 2)/4)) ) ); //подсчет выражения
    b = x - pow(x, 2)/6 + pow(x, 5)/120; //подсчет выражения

    if (y < 0)
        y = ~y + 1;
    if (x < 0)
        x = ~x + 1;

    printf("Result: a = %.4f   b = %.4f   x = %o   y = %x", a, b, x, y); //форматный вывод значений a, b, x, y

    return 0;
}