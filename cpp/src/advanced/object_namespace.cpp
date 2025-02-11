#include "object_namespace.h"

using namespace std;
using namespace People;


Persona::Persona( ) : 
nome("nd"), eta(0) {;} // costruttore di default
Persona::Persona(const string& iname, int ieta) : nome(iname), eta(ieta) {;}   // costruttore sovraccaricato overload
void Persona::print_info() const { // using when not changing return
  cout << "Informazioni Persona" << endl;
  cout << "Nome "<< nome << endl;
  cout << "Età " << eta  <<endl;
}


Studente::Studente(const string& iname, int ieta, 
                  const string& imatricola, 
                  const string& icorso_di_studi)
: 
Persona(iname, ieta), 
matricola(imatricola), 
corso_di_studi(icorso_di_studi) {;}

void Studente::stampa_studente() const {
  print_info();
  cout << "Informazioni Studente" << endl;
  cout << "Matricola "<< matricola << endl;
  cout << "Corso di studi " << corso_di_studi  <<endl;
}



/*
test
*/
void classes_namespace_example() {
  People::Studente studente_casuale = People::Studente("Luca", 30 , "figc435", "informatica");
  studente_casuale.stampa_studente();
}

