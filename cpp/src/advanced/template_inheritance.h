#ifndef TEMPLATE_INHERIT_HPP
#define TEMPLATE_INHERIT_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
class Pair {
  private:
    T first;
    U second;
  public:
    Pair(T first, U second); // costruttore
    void set_value(T f, U s) ; // setter
    T get_first() const ; // getter
    U get_second() const ;
};

// needed
template <typename T, typename U>
class LabeledPair : public Pair<T, U> {
  private:
    string label;
  public:
    LabeledPair(T first, U second, string label);
    void stampa_label() const ;
};

void inheritance_template_example ();

#endif