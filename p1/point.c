#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <point.h>

struct _Point {
int x, y;
char symbol;
Bool visited; // for DFS
};

typedef struct _Point Point;

Point * point_new (int x, int y, char symbol) {
    Point * v;    //creamos un punto
    v = (Point *) malloc (sizeof(Point));   //reservamos memoria para un punto
    v->x = x;
    v->y = y;
    v->symbol = symbol;   // inicializamos el punto con los valores pasados como parámetros a la función
    return * v;     // devolvemos el punto
}

void point_free (Point *p) {
    free(p);        // liberamos la memoria 
}

int point_getCoordinateX (const Point *p) {
    int x;
    x = p->x;        // declaramos un entero y copiamos la coordenada x del punto en el entero
    if (x==NULL) {
        return INT_MAX;         // si hay un error devolvemos INT_MAX
    } else {
        return x;           // si no hay ningun error devolvemos el entero que contiene la coordenada x
    }
}

int point_getCoordinateY (const Point *p) {
    int y;
    y = p->y;       //declaramos un entero y copiamos la coordneada y del punto en el entero
    if (y==NULL) {
        return INT_MAX;         // si hay un error devolvemos INT_MAX
    } else {
        return y;           // si no hay ningun error devolvemos el entero que contiene la coordenada y
    }
}

char point_getSymbol (const Point *p) {
    char symbol;
    symbol = p->symbol;         //declaramos una cadena de caracteres y copiamos el symbolo del punto en la variable
    if (symbol==INPUT || symbol==OUTPUT || symbol==BARRIER || symbol==SPACE) {
        return symbol;          // si no hay errores devolvemos el symbolo del punto
    } else {
        return ERRORCHAR;       // si hay algun error devolvemos ERRORCHAR
    }
}

Status point_setCoordinateX (Point *p, int x) {
    if (x==NULL || x<0) {
        return 0;       // si hay un error o la coordenada es negativa, devolvemos 0, que es error
    } else {
        p->x = x;
        return 1;       // si no hay ningún error, modificamos la x del punto que ha sido pasado como argumento,
    }                   // que pasa a ser el entero pasado como segundo argumento, y devolvemos 1 para indicar que no hay error
}

Status point_setCoordinateY (Point *p, int y) {
    if (y==NULL || y<0) {
        return 0;       // si hay un error o la coordenada es negativa, devolvemos 0, que es error
    } else {
        p->y = y;       // si no hay ningún error, modificamos la y del punto que ha sido pasado como argumento,
        return 1;       // que pasa a ser el entero pasado como segundo argumento, y devolvemos 1 para indicar que no hay error
    }
}

Status  point_setSymbol (Point *p, char c) {
    if (c==INPUT || c==OUTPUT || c==BARRIER || c==SPACE) {
        p->symbol = c;
        return 1;       // si no hay ningún error, modificamos el symbol del punto que ha sido pasado como argumento,
    } else {            // que pasa a ser el symbol pasado como segundo argumento, y devolvemos 1 para indicar que no hay error
        return 0;       // si hay algun error devolvemos 0 que indica error
    }
}

Point *point_hardcpy (const Point *src) {
    Point * v; 
    v = (Point *) malloc (sizeof(Point));       // declaramos un Point y reservamos 1 espacio de memoria
    v->x = src->x;
    v->y = src->y;
    v->symbol = src->symbol;        // introducimos en el point creado los valores del point que ha sido pasado como argumento
    return * v;                     // devolvemos el point creado
    
}

Bool point_equal (const void *p1, const void *p2) {
    if (p1->x == p2->x) {
        if (p1->y == p2->y) {
            if (p1->symbol == p2->symbol) {         // comprobamos que todas las partes del point1 son iguales que el point2
                return 1;                           // y devolvemos 1 que es TRUE si son iguales
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;           // en caso de que no coincida en alguna variable, devolvera 0 que indica que es falso
    }
}


