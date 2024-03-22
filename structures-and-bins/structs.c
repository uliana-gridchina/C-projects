#include <stdio.h>

typedef struct num {
    int x;
    int y;
    int z;
} vector;

struct num create(int x, int y, int z) {
    struct num vec = {x, y, z};
    return vec;
}

struct num sum(const struct num v1, const struct num v2) {
    return (struct num) {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z};
}

vector dif(const vector* v1, const vector* v2) {
    struct num vec = {v1->x-v2->x, v1->y-v2->y, v1->z-v2->z};
    return vec;
}

void mul(vector* v1, const vector* v2) {
    v1->x *= v2->x;
    v1->y *= v2->y;
    v1->z *= v2->z;
}

int main() {
    struct num dig;
    dig.x = 10; //только для переменных

    struct num *ptr_dig;
    ptr_dig = &dig;
    (*ptr_dig).y = 9; //то же самое что и:
    ptr_dig -> z = 7; //только для указателей

    printf("x = %d  y = %d  z = %d\n", ptr_dig->x, (*ptr_dig).y, dig.z);

    struct num one = create(1, 2, 3);
    struct num two = {.y = 13};
    two.x = 3;
    struct num three = sum(one, two);

    printf("first {%d, %d, %d}\nsecond {%d, %d, %d}\nthird {%d, %d, %d}\n\n", one.x, one.y, one.z, two.x, two.y, two.z, three.x, three.y, three.z);

    struct num on = create(1, 2, 3);
    struct num tw = {.y = 13};
    tw.x = 3;
    vector thre = dif(&on, &tw);

    printf("first {%d, %d, %d}\nsecond {%d, %d, %d}\nthird {%d, %d, %d}\n\n", on.x, on.y, on.z, tw.x, tw.y, tw.z, thre.x, thre.y, thre.z);

    vector o = create(1, 2, 3);
    vector t = {.y = 13};
    t.x = 3;
    printf("first {%d, %d, %d}\nsecond {%d, %d, %d}\n", o.x, o.y, o.z, t.x, t.y, t.z);
    mul(&o, &t);

    printf("first {%d, %d, %d}\nsecond {%d, %d, %d}\n\n", o.x, o.y, o.z, t.x, t.y, t.z);

    printf("first {%d, %d, %d}\n", o.x, o.y, o.z);
    mul(&o, &(struct num){1, 3, 5});
    printf("first {%d, %d, %d}\n", o.x, o.y, o.z);


    return 0;
}