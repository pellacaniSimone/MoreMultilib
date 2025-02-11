#include "var.h"
using namespace std;
int GLOBALE_VAR = 5; // accessible everywhere

int globaleFun() {
  int local_var = 6; // visibility
  GLOBALE_VAR = local_var;
  int x = 6;
  return x + GLOBALE_VAR + local_var;
}

int staticFun() {
  static const int INC = 100000;
  return INC;
}


int variabileStaticaGlobale = 100;
void funzioneStaticaGlobale() {
  cout << "Funzione statica a livello di file: variabileStaticaGlobale = " << variabileStaticaGlobale << endl;
}


/**
 * @brief Classe
 * 
 */
// private
int Classe::variabileDiClasse = 200; // static
void Classe::metodoPrivato() { cout << "Metodo privato chiamato" << endl; }
// protected
void Classe::metodoProtetto() {  cout << "Metodo protetto chiamato" << endl; }
// public static
void Classe::mostraVariabileDiClasse() { cout << "Classe::variabileDiClasse = " << variabileDiClasse << endl; }
// public
void Classe::metodoPubblico() {
  cout << "Metodo pubblico chiamato" << endl;
  metodoPrivato();  // Può chiamare il metodo privato dall'interno della classe
}

Classe::~Classe(){;}
Classe::Classe(int val) : privateVar(val * 3), protectedVar(val * 2), publicVar(val) {;} // order is needed as declared

/**
 * @brief ClasseDerivata
 * 
 */
ClasseDerivata::ClasseDerivata(int val) : Classe(val) {;} //definition where the construnctor situated
void ClasseDerivata::metodoDerivato() {
  cout << "Classe derivata, metodo derivato:" << endl;
  cout << "  Variabile protetta = " << protectedVar << endl;  
  metodoProtetto(); 
}


/**
 * @brief test
 * 
 */
void test_visibilita() {
  Classe oggettoClasse(5);

  // Accesso alla variabile e metodo pubblici
  oggettoClasse.publicVar = 10;
  cout << "Variabile pubblica: " << oggettoClasse.publicVar << endl;
  oggettoClasse.metodoPubblico();

  // Accesso alla funzione globale
  globaleFun();

  // Creazione di un oggetto della classe derivata
  ClasseDerivata oggettoDerivato(8);
  oggettoDerivato.metodoDerivato();  // Accesso consentito al metodo pubblico della classe derivata

  // Tentativi di accesso diretto a variabili e metodi protetti e privati - causerebbero errori
  // oggettoClasse.protectedVar = 15;  // Errore di compilazione: protectedVar non accessibile
  // oggettoClasse.privateVar = 20;    // Errore di compilazione: privateVar non accessibile
  // oggettoClasse.metodoPrivato();    // Errore di compilazione: metodoPrivato non accessibile
  funzioneStaticaGlobale();
}


