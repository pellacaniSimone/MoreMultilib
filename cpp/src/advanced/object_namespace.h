#ifndef OOP_NS_HPP
#define OOP_NS_HPP

#include <iostream>
#include <string>

using namespace std;

namespace People {
  class Persona {
    private:
      string nome; // default value
      int eta ;
    public:
      Persona() ; // costruttore di default
      Persona(const string& iname, int ieta);
      virtual void print_info() const; // polimorphic <-- virtual
  };

  class Studente : public Persona {
    private:
      string matricola;
      string corso_di_studi ;

    public:
      Studente() ; // costruttore default
      Studente(const string& iname, int ieta, 
                  const string& imatricola, 
                  const string& icorso_di_studi) ;
      void stampa_studente() const ; // not polimorphic
  };
}

void classes_namespace_example();

#endif