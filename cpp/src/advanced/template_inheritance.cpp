#include "template_inheritance.h"


template <typename T, typename U>
Pair<T, U>::Pair(T first, U second) 
    : first(first), second(second) {;}

template <typename T, typename U>
void Pair<T, U>::set_value(T f, U s) {  first = f; second = s; } // setter
template <typename T, typename U>
T Pair<T, U>::get_first() const { return first; } // getter
template <typename T, typename U>
U Pair<T, U>::get_second() const { return second; }


template <typename T, typename U>
LabeledPair<T, U>::LabeledPair(T first, U second, string label)
    : Pair<T, U>(first, second), label(label) {;}
template <typename T, typename U>
void LabeledPair<T, U>::stampa_label() const { cout << "Label: " << label << endl;  }

void inheritance_template_example () {
  Pair<int, double> p(10, 20.5); // Creazione di un oggetto Pair
  cout << "First: " << p.get_first() << ", Second: " << p.get_second() << endl;

  LabeledPair<int, double> lp(30, 40.5, "Example Label"); // Creazione di un oggetto LabeledPair
  cout << "First: " << lp.get_first() << ", Second: " << lp.get_second() << endl;
  lp.stampa_label();
}


