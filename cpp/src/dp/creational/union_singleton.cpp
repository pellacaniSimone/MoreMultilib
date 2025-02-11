#include "union_singleton.h"


// static singleton getter
uSingleton& uSingleton::getInstance() { static uSingleton instance; return instance;  }

void uSingleton::setValue(int valore)   { data.intero = valore; currentType = DataType::INT; }
void uSingleton::setValue(float valore) { data.decimale = valore; currentType = DataType::FLOAT; }
void uSingleton::setValue(char valore)  { data.carattere = valore; currentType = DataType::CHAR; }

void uSingleton::printValue() const {
  switch (currentType) {
    case DataType::INT:   cout << "Valore (int): "   << data.intero    << endl; break;
    case DataType::FLOAT: cout << "Valore (float): " << data.decimale  << endl; break;
    case DataType::CHAR:  cout << "Valore (char): "  << data.carattere << endl; break;
    default: cout << "Nessun valore impostato." << endl; break;
  }
}

void union_singleton() {
  uSingleton& singleton = uSingleton::getInstance();

  singleton.setValue(42);
  singleton.printValue(); 

  singleton.setValue(3.14f);
  singleton.printValue();  

  singleton.setValue('f');
  singleton.printValue(); 
}
