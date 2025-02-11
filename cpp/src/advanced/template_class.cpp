#include "template_class.h"



template <typename T>
void Container<T>::set_value(T v) { value = v; }
template <typename T>
T Container<T>::get_value() const { return value; }

void template_example(){

  Container<int> intContainer;
  intContainer.set_value(42);
  cout << "Int value: " << intContainer.get_value() << endl;

  Container<float> floatContainer;
  floatContainer.set_value(3.14f);
  cout << "Float value: " << floatContainer.get_value() << endl;

  Container<string> stringContainer;
  stringContainer.set_value("Hello, World!");
  cout << "String value: " << stringContainer.get_value() << endl;
}