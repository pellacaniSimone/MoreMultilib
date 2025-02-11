
import time
class Decorators:
  @staticmethod # avoid Decorators.time_execution() takes 1 positional argument but 2 were given
  def time_execution(func):
    def wrapper(*args, **kwargs):
      start_time = time.time() 
      result = func(*args, **kwargs)
      end_time = time.time()
      print(f"Tempo di esecuzione: {end_time - start_time} secondi")
      return result 
    return wrapper
  @staticmethod
  def deriveDebug(cls):
    """Decoratore che aggiunge un metodo __repr__ per la stampa di debug."""
    def __repr__(self):
      attrs = ", ".join(f"{k}={repr(v)}" for k, v in self.__dict__.items())
      return f"{cls.__name__}({attrs})"
    cls.__repr__ = __repr__
    return cls

@Decorators.deriveDebug
class Persona:
  def __init__(self, nome: str, eta: int):
    self.nome = nome
    self.eta = eta


@Decorators.time_execution
def calcola_quadrato(numero):
  return numero ** 2

class TestDecorators:
  @classmethod
  def run(cls):
    #print(calcola_quadrato(7))
    #print(calcola_quadrato(10000000000000000000000000000000000000))
    p = Persona("Alice", 30)
    print("Stampa di debug")
    print(p)  # Output: Persona(nome='Alice', eta=30)
    print("Stampa normale")
    print(f"Nome: {p.nome} - età: {p.eta}")


