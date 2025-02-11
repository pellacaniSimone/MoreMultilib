#include "multiple_inheritance.h"


// costruttore e distruttore virtuale non necessari
void VeicoloGenerico::muovi() { cout << "Non raggiungibile, errore" << endl; } // virtual in class declaration only
void Auto::muovi()  { cout << "Veicolo Auto da ora" << endl; } // override must be explicit in class declaration only
void Auto::guida() { muovi(); cout << "Guida su strada" << endl; }
void Barca::muovi()  { cout << "Veicolo Barca da ora" << endl; } 
void Barca::naviga() { muovi(); cout << "Naviga sull'acqua" << endl; }
void AmphibiousCar::muovi() { cout << "Veicolo anfibio in movimento da ora" << endl; }

void advanced_class_example(){

  cout << "--- Test AmphibiousCar ---" << endl;

  Barca boat;
  Auto car;
  AmphibiousCar amphibious;
  car.guida();             // Output: "Guida su strada"
  boat.naviga();           // Output: "Naviga sull'acqua"
  amphibious.muovi();      // Output: "Veicolo anfibio in movimento"
  amphibious.naviga();
  amphibious.guida();

  cout << "--- Test polimorfismo ---" << endl;

  const int VEICOLI=3;
  VeicoloGenerico** vettoreVeicoli = new VeicoloGenerico*[VEICOLI];
  vettoreVeicoli[0] = new Barca();
  vettoreVeicoli[1] = new Auto();
  vettoreVeicoli[2] = new AmphibiousCar();

  // polimorph, si usa il puntatore
  for (int i = 0; i < VEICOLI; i++) { vettoreVeicoli[i]->muovi(); }

  // Deallocazione della memoria
  for (int i = 0; i < VEICOLI; i++) { delete vettoreVeicoli[i]; }
  delete[] vettoreVeicoli;

}
