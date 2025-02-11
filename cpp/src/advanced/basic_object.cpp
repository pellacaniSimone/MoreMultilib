#include "basic_object.h"

Counter::~Counter() {;}   // di base
Counter::Counter() : value(0) {;}  // default
Counter::Counter(int offset) : value(offset) {;}   
void Counter::increment() { value++;}
void Counter::print_info() const { cout << "Counter value: " << value << endl; }


void basic_class_example() {
  Counter c ;
  c.print_info();
  c.increment();
  c.print_info();
}

