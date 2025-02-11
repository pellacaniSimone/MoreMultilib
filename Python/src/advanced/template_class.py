
from typing import Generic, TypeVar

# tipi generici
T = TypeVar('T')

class Container(Generic[T]):
  """classe generica singolo valore"""
  def __init__(self, val: T):
    self.val = val
  def set_value(self, f: T):
    self.val = f
  def get_value(self) -> T:
    return self.val

class TestGenerics:
  @classmethod
  def run(cls):
    p = Container(42)
    print(f"Int value: {p.get_value()} ")
    p.set_value(3.14)
    print(f"Float value: {p.get_value()} ")
    p.set_value("Hello, World!")
    print(f"String value: {p.get_value()} ")
    p.set_value(1+2j)
    print(f"Complex value: {p.get_value()} ")
