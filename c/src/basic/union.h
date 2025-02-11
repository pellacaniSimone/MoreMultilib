#ifndef UNION_H
#define UNION_H
#include <stdio.h> // printf

// a differenza della struct conserva
// in memoria solo l'ultimo tipo di dato usato
union Dato {
  int intero;
  float decimale;
  char carattere;
};

void union_test();
#endif
