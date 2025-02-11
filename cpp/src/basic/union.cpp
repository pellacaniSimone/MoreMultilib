#include "union.h"

using namespace std;

void union_test() {
  Dato dato;
  dato.intero = 42;
  cout << "Intero: " << dato.intero << endl;
  dato.decimale = 3.14f;
  cout << "Decimale: " << dato.decimale << endl;
  dato.carattere = 'A';
  cout << "Carattere: " << dato.carattere << endl;
}