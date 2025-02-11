
from typing import Union

class DatoUnion:
  def __init__(self, value) -> None:
    self.value: Union[int, float, str] = value

  def __str__(self) -> str:
    if isinstance(self.value, int) or isinstance(self.value, float):
      return (f"Intero: {int(self.value)}\n"
              f"Virgola Mobile (interpretazione float): {float(self.value)}\n"
              f"Carattere castato ascii: {ord(str(self.value)[0] )}")
    else:
      return (f"Intero: {ord(self.value[0])}\n"
              f"Virgola Mobile (interpretazione float): {ord(self.value[0])}\n"
              f"Carattere castato ascii: {ord(str(self.value)[0] )}")


class TestUnion:
  @classmethod
  def run(self):
    dato = DatoUnion(42)
    print("Dopo aver assegnato 'value = 42':")
    print(dato)
    dato = DatoUnion(3.14)
    print("\nDopo aver assegnato 'value = 3.14':")
    print(dato)
    dato = DatoUnion('a')  
    print("\nDopo aver assegnato 'a':")
    print(dato)