#include "var.h"

int GLOBALE_VAR = 6; // extern

int globaleFun() {
  int local_var = 6; // visibility
  GLOBALE_VAR = local_var;
  int x = 6;
  return x + GLOBALE_VAR + local_var;
}

int staticFun() {
  static const int INC = 100000;
  return INC;
}
