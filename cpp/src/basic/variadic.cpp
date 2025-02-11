#include "variadic.h"
using namespace std;

template <typename T>
T sum(T value) { return value; }

template <typename T, typename... Args>
T sum(T first, Args... args) { return first + sum(args...); }  // recoursive call

void variadic_test () {
  cout << "Sum: " << sum(1, 2, 3) << endl;         // Somma 1 + 2 + 3
  cout << "Sum: " << sum(1, 2, 3, 4, 5) << endl;   // Somma 1 + 2 + 3 + 4 + 5
}


