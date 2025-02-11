#ifndef FACTORY_H

#define FACTORY_H
#include <stdlib.h> // malloc
#include <stdio.h> // print
#include <math.h>
#include <string.h>

typedef struct Shape {
  void (*draw)(struct Shape*);  // metavirtual
} Shape;

// some kind of inherit
typedef struct {
  Shape base;
  int radius;
} Circle;

typedef struct {
  Shape base;
  int side;
} Square;

void  factory_example() ;
#endif
