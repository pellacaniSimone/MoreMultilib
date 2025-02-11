#ifndef B_OBLECT_H
#define B_OBLECT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Counter {
    int value;  // attributo dell'oggetto

    void (*increment)(struct Counter *self); // function pointer
    void (*print)(struct Counter *self);
} Counter;


void metaobject();

#endif
