
class SumCalculator:
  @staticmethod
  def sum(*args):
    if not args:
      raise ValueError("Deve essere passato almeno un valore per la somma.")
    if len(args) == 1:
      return args[0]
    return args[0] + SumCalculator.sum(*args[1:])

  def variadic_test(cls):
    print("Sum:", SumCalculator.sum(1, 2, 3))          # Somma 1 + 2 + 3
    print("Sum:", SumCalculator.sum(1, 2, 3, 4, 5))    # Somma 1 + 2 + 3 + 4 + 5

  @classmethod
  def run(cls):
    p=SumCalculator()
    p.variadic_test()