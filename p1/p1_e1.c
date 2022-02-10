#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAM 4


struct _Point {
int x, y;
char symbol;
Bool visited; // for DFS
};

typedef struct _Point Point;

int main() {
    Point *p[TAM];
    p[0] = point_new(0, 0, "BARRIER");
    p[1] = point_new(0, 1, "BARRIER");

    printf("%d, %d, %s\n, este es el primer punto", p[0]->x, p[0]->y, p[0]->symbol);
    printf("%d, %d, %s\n, este es el segundo punto", p[1]->x, p[1]->y, p[1]->symbol);

    printf("%s", point_equal(p[0], p[1]));

    p[2] = point_hardcpy(p[0]);

    printf("%d, %d, %s, este es el tercer punto", p[2]->x, p[2]->y, p[2]->symbol);

    printf("%s", point_equal(p[0], p[2]));

    point_setSymbol(p[2], "SPACE");

    printf("%s", point_equal(p[0], p[2]));

    p[3] = point_hardcpy(p[0]);

    point_setSymbol(p[3], "OUTPUT");

    printf("%d, %d, %s\n, este es el primer punto", p[0]->x, p[0]->y, p[0]->symbol);
    printf("%d, %d, %s\n, este es el segundo punto", p[1]->x, p[1]->y, p[1]->symbol);
    printf("%d, %d, %s, este es el tercer punto", p[2]->x, p[2]->y, p[2]->symbol);
    printf("%d, %d, %s, este es el cuarto punto", p[3]->x, p[3]->y, p[3]->symbol);
}