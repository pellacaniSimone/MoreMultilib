#include "basic_namespace.h"
using namespace std;
// definizione del namespace
namespace math_operations {
  double somma(double a, double b) { return a + b; }
  double sottrazione(double a, double b) { return a - b;  }
  double moltiplicazione(double a, double b) { return a * b; }
  double divisione(double a, double b) { return (b==0) ? 0 : a/b ; }
}

void namespace_example() {
  double x = 10.5, y = 2.5;
  cout << "Somma: " << math_operations::somma(x, y) << endl;
  cout << "Sottrazione: " << math_operations::sottrazione(x, y) << endl;
  cout << "Moltiplicazione: " << math_operations::moltiplicazione(x, y) << endl;
  cout << "Divisione: " << math_operations::divisione(x, y) << endl;
}
