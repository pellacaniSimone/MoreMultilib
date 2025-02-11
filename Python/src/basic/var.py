""" -------------------------------------------------
  Scope e Lifetime delle Variabili
  Demonstrates:
  - Global variables with 'global' keyword
  - Class attributes and methods
  - Name mangling with double underscore
  - Class-level vs instance attributes
  - Inheritance and access control simulation
  - __dict__ class access
    -------------------------------------------------
"""


from typing import Final

variabile_globale = 10 # implicit global

def funzione_globale():
  global variabile_globale # va chiamata subito
  print(f"Funzione globale: variabile_globale = {variabile_globale}")
  # global variabile_globale # errore
  variabile_globale+=variabile_globale
  print(f"Funzione globale modificata = {variabile_globale}")

_variabile_statica_globale = 100

def _funzione_statica_globale():
  print(f"Funzione statica a livello di modulo: _variabile_statica_globale = {_variabile_statica_globale}")

class ClasseEp1:
  variabile_di_classe : Final[int]= 200

  def __init__(self, val):
    self.public_var = val
    self._protected_var = val * 2
    self.__private_var = val * 3

  def metodo_pubblico(self):
    print("Metodo pubblico chiamato")
    self.__metodo_privato()

  def _metodo_protetto(self):
    print("Metodo protetto chiamato")

  def __metodo_privato(self):
    print("Metodo privato chiamato")

class ClasseDerivataEp1(ClasseEp1):
  def metodo_derivato(self):
    print("Classe derivata, metodo derivato:")
    print(f"  Variabile protetta = {self._protected_var}")
    self._metodo_protetto()

  @classmethod
  def run(cls):
    """
    # Scope e Lifetime delle Variabili
    """
    oggetto_classe = ClasseEp1(5)
    oggetto_classe.metodo_pubblico()
    funzione_globale()
    oggetto_derivato = ClasseDerivataEp1(8)
    oggetto_derivato.metodo_derivato()
    # Accesso indiretto alla variabile privata tramite __dict__
    print("Accesso indiretto alla variabile privata tramite dict:")
    print(oggetto_classe.__dict__['_ClasseEp1__private_var'])
    _funzione_statica_globale()
