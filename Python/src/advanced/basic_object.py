
class Persona:
  def __init__(self, nome="nd", eta=0):
    # Costruttore con valori di default per nome e eta
    self.nome = nome
    self.eta = eta
    if nome != "nd" or eta != 0:
      print("Costruttore parametrizzato chiamato")

  def print_info(self):
    print("Informazioni Persona")
    print(f"Nome: {self.nome}")
    print(f"Età: {self.eta}")


class Studente(Persona):
  def __init__(self, nome="nd", eta=0, matricola="ND", corso_di_studi="ND"):
    super().__init__(nome, eta)
    self.matricola = matricola
    self.corso_di_studi = corso_di_studi

  def stampa_studente(self):
    self.print_info()
    print("Informazioni Studente")
    print(f"Matricola: {self.matricola}")
    print(f"Corso di studi: {self.corso_di_studi}")

  @classmethod
  def run(cls):
    studente_casuale = cls("Luca", 30, "figc435", "informatica")
    studente_casuale.stampa_studente()


# intermediate, ereditarietà multipla advanced_class_example
