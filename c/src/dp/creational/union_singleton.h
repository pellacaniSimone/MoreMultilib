#ifndef UNION_SINGLETON_H
#define UNION_SINGLETON_H
#include <stdio.h> // print
#include <stdlib.h> // malloc

typedef struct {
  union {
    int intero;
    float decimale;
    char carattere;
  };
  char type;  // flag data type use
} uSingleton;

void union_singleton() ;

#endif
