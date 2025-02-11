#include "variadic.h"

static int variadic_sum(int count, ...) {
  va_list args; // Definizione della lista di argomenti variabili
  int total = 0;

  va_start(args, count); // Inizializza la lista di argomenti
  for (int i = 0; i < count; i++) {
    total += va_arg(args, int); // Estrae ogni argomento come int e lo somma
  }
  va_end(args); // Chiude la lista di argomenti

  return total;
}

void variadic_test() {
  printf("Sum: %d\n", variadic_sum(3, 1, 2, 3));  // Somma 1 + 2 + 3
  printf("Sum: %d\n", variadic_sum(5, 1, 2, 3, 4, 5));  // Somma 1 + 2 + 3 + 4 + 5
}