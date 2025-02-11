#include "mro.h"



void A::method() {cout << "Metodo di A L0" << endl; }

void B::method() { 
  cout << "Metodo di B L1" << endl;
  A::method();  // chiamata diretta ad A
}

void C::method()  { 
  cout << "Metodo di C L1" << endl;
  A::method();  // chiamata diretta ad A
}

void D::method()  {
  cout << "Metodo di D L2" << endl;
  B::method();  // manual resolution order
  C::method(); 
}

void mro_example() { D d; d.method(); }

