#include <stdio.h>  //библиотека с output/input
#include <math.h>   //библиотека для математических функций
#include <stdbool.h> //определение типа bool с константами true и false

//булевая функция, возвращающая истинность выражения
bool area(float x, float y) {

    return ( (y <= x/2) && ((pow(x, 2) + pow(y, 2)) <= 1) );

}

int main() {

    float x, y;
    printf("Enter the coordinates x and y of the point: \n");
    scanf_s("%f %f", &x, &y); //считывание значений, вводимых с клавиатуры

    //вложенные условные операторы с простыми условиями
    if ( y <= x/2 )
        if ( (pow(x, 2) + pow(y, 2)) <= 1 )
            printf("FIRST WAY: The point belongs to the shaded area\n");
        else
            printf("FIRST WAY: The point doesn't belong to the shaded area\n");
    else
        printf("FIRST WAY: The point doesn't belong to the shaded area\n");

    //условный оператор со сложным логическим выражением
    if ( (y <= x/2) && ((pow(x, 2) + pow(y, 2)) <= 1) )
        printf("SECOND WAY: The point belongs to the shaded area\n");
    else
        printf("SECOND WAY: The point doesn't belong to the shaded area\n");

    //условный оператор с условием в виде истинности значения, возвращаемого функцией
    if (area(x, y))
        printf("THIRD WAY: The point belongs to the shaded area");
    else
        printf("THIRD WAY: The point doesn't belong to the shaded area");

    (x < 3) ? ( (x == 1) ? 1 : 0 ) : -1;


    return 0;
}