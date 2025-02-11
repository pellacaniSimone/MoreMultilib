#ifndef VAR_HPP
#define VAR_HPP

#include <iostream>

extern int GLOBALE_VAR; // accessible everywhere
int globaleFun() ;
int staticFun();

class Classe {
  private:
    int privateVar;  
    void metodoPrivato() ;
  protected:
    int protectedVar;     
    void metodoProtetto();
  public:
    static int variabileDiClasse;  // like @static
    int publicVar; // accessibile ovunque l'oggetto sia accessibile
    static void mostraVariabileDiClasse();
    void metodoPubblico() ;
    Classe(int val);
    ~Classe() ;
};

class ClasseDerivata : public Classe {
  public:
    ClasseDerivata(int val);
    void metodoDerivato() ; // like a getter
};

void test_visibilita();

#endif