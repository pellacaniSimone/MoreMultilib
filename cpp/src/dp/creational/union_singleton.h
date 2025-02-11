#ifndef UNION_SING_HPP
#define UNION_SING_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

class uSingleton {
  private:
    enum class DataType { NONE, INT, FLOAT, CHAR }; // tipo di dato

    union Data {
      int intero;
      float decimale;
      char carattere;
      Data() : intero(0) {} // costruttore di default
    } data ;

    DataType currentType;

    uSingleton() : currentType(DataType::NONE) {}

  public:
    uSingleton(const uSingleton&) = delete; // private
    uSingleton& operator=(const uSingleton&) = delete;

    static uSingleton& getInstance();

    void setValue(int val);
    void setValue(float val);
    void setValue(char val);

    void printValue() const;

};

void union_singleton() ;

#endif