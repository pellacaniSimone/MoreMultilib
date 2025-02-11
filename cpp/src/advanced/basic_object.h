#ifndef B_OOP_HPP
#define B_OOP_HPP

#include <iostream>
#include <memory>

using namespace std;

class Counter {
  private:
    int value;
  public:
    ~Counter();
    Counter() ; // costruttore di default
    Counter( int );
    void increment() ;
    void print_info() const;
};

void basic_class_example();

#endif