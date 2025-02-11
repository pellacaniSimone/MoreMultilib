#include "singleton.h"

Singleton* instance = NULL;

static Singleton* getInstance() {
  if (instance == NULL) {
    instance = (Singleton*) malloc(sizeof(Singleton));
    instance->valore = 0;
  }
  return instance;
}

static void destroyInstance() {
  if (instance != NULL) {
    free(instance);
    instance = NULL; // dangling pointer
  }
}

void test_singleton() {
  Singleton* s1 = getInstance();
  s1->valore = 42;
  Singleton* s2 = getInstance();
  printf("Valore di s2: %d\n", s2->valore);
  if (s1 == s2) { printf("s1 e s2 puntano alla stessa istanza\n");  }
  destroyInstance();
}
