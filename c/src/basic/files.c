#include "files.h"

static void crea_file_vuoto() {
  FILE *fptr;
  fptr = fopen("filename.txt", "w");
  fclose(fptr);
}

static void Scrivi_su_un_file_nuovo() {
  FILE *fptr;
  fptr = fopen("filename2.txt", "w");
  fprintf(fptr, "Some text");
  fclose(fptr);
}

static void leggi_file_e_stampa() {
  FILE *fptr;
  fptr = fopen("filename2.txt", "r");
  const int MAX=80;
  char stringa[MAX] ;

  while(fgets(stringa, MAX, fptr))
    printf("%s", stringa);

  fclose(fptr);
  printf("\n");
}

void files_handling() {
  crea_file_vuoto();
  Scrivi_su_un_file_nuovo();
  leggi_file_e_stampa();
}
