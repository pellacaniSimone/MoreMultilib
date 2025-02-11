#include "files.h"

static void crea_file_vuoto() {
  ofstream file("filename.txt");
}

static void Scrivi_su_un_file_nuovo() {
  ofstream file("filename2.txt");
  if (file.is_open()) 
    file << "Some text";
}

static void leggi_file_e_stampa() {
  ifstream file("filename2.txt");
  if (file.is_open()) {
    string line;
    while (getline(file, line)) 
      cout << line << endl;
  }
}


void files_handling() {
  crea_file_vuoto();
  Scrivi_su_un_file_nuovo();
  leggi_file_e_stampa();
}
