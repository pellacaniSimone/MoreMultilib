
from typing import Generic, TypeVar

# tipi generici
T = TypeVar('T')
U = TypeVar('U')

class Pair(Generic[T, U]):
  """classe generica coppia di valori"""
  _nascosto="Sono un segreto"
  def __init__(self, first: T, second: U):
    self.first = first
    self.second = second
  def set_value(self, f: T, s: U):
    self.first = f
    self.second = s
  def get_first(self) -> T:
    return self.first
  def get_second(self) -> U:
    return self.second

class LabeledPair(Pair[T, U]):
  """aggiunge l'etichetta"""
  def __init__(self, first: T, second: U, label: str):
    super().__init__(first, second)
    self.label = label

  def stampa_label(self):
    print(f"Label: {self.label}")


class TestGenericsInheritance:
  @classmethod
  def run(cls):
    p = Pair(10, 20.5)
    print(f"First: {p.get_first()}, Second: {p.get_second()}")

    lp = LabeledPair(30, 40.5, "Example Label")
    print(f"First: {lp.first}, Second: {lp.second} , {lp.label} , {lp._nascosto}")

