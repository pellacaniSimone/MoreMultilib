#ifndef MULTI_INHERIT_HPP
#define MULTI_INHERIT_HPP

#include <iostream>
using namespace std;

class VeicoloGenerico {
  public:
    VeicoloGenerico() = default; // not virtual
    virtual ~VeicoloGenerico() = default; // prevent undefined behavior
    virtual void muovi() ;
};

class Auto : public virtual VeicoloGenerico {
  public: 
    void muovi() override; // override keyword needed vith virtual methods
    void guida();
};

class Barca : public virtual VeicoloGenerico {
  public: 
    void muovi()override; // override keyword needed vith virtual methods
    void naviga();
};

class AmphibiousCar : public Auto, public Barca {
  public:
    void muovi()override; // override keyword needed vith virtual methods
};

void advanced_class_example();

#endif