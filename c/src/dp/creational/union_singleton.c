#include "union_singleton.h"

uSingleton* instanceU = NULL;

static uSingleton* getInstanceU() {
  if (instanceU == NULL) {
    instanceU = (uSingleton*) malloc(sizeof(uSingleton));
    instanceU->intero = 0;
    instanceU->decimale = 0.0f;
    instanceU->carattere = 'c';
  }
  return instanceU;
}

static void setIntValue(int valore) {
  uSingleton* singleton = getInstanceU();
  singleton->intero = valore;
  singleton->type = 'i';
}

static void setFloatValue(float valore) {
  uSingleton* singleton = getInstanceU();
  singleton->decimale = valore;
  singleton->type = 'f';
}

static void setCharValue(char valore) {
  uSingleton* singleton = getInstanceU();
  singleton->carattere = valore;
  singleton->type = 'c';
}

static void printValue() {
  uSingleton* singleton = getInstanceU();
  switch (singleton->type) {
    case 'i': printf("Valore (int): %d\n", singleton->intero); break;
    case 'f': printf("Valore (float): %f\n", singleton->decimale); break;
    case 'c': printf("Valore (char): %c\n", singleton->carattere); break;
  }
}

static void destroyInstanceU() {
  if (instanceU != NULL) {
    free(instanceU);
    instanceU = NULL;
  }
}

void union_singleton() {
    setIntValue(42);
    printValue();

    setFloatValue(3.14f);
    printValue();

    setCharValue('f');
    printValue();

    destroyInstanceU();
}
