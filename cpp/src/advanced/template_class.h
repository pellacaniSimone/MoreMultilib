#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
using namespace std;

template <typename T>
class Container {
  private:
    T value;
  public:
    void set_value(T v) ; // setter
    T get_value() const ; // getter
};

void template_example();

#endif