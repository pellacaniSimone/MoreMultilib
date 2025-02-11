#ifndef MRO_HPP
#define MRO_HPP

#include <iostream>
using namespace std;

class A {
  public:
    virtual void method() ;
};
class B : virtual public A {
  public:
    void method() override ;
};
class C : virtual public A {
  public:
    void method() override ;
};
class D : public B, public C {
  public:
    void method() override;
};

void mro_example() ;

#endif