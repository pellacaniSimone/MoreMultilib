class filesHandling:
  def crea_file_vuoto(self):
    with open("filename.txt", "w") as file:
      pass  # Il file viene creato e chiuso automaticamente

  def scrivi_su_un_file_nuovo(self):
    with open("filename2.txt", "w") as file:
      file.write("Some text\n")  # Scrive testo nel file e lo chiude automaticamente

  def leggi_file_e_stampa(self):
    try:
      with open("filename2.txt", "r") as file:
        for linea in file:
          print(linea.strip())  # Stampa ogni linea, rimuovendo newline finale
    except FileNotFoundError:
      print("Errore nell'apertura del file.")
      exit(2)

  @classmethod
  def run(cls):
    p=filesHandling()
    p.crea_file_vuoto()
    p.scrivi_su_un_file_nuovo()
    p.leggi_file_e_stampa()