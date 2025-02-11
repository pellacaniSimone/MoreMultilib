class Singleton:
    _instance = None
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance.valore = 0  # Inizializzazione diretta in __new__
        return cls._instance


class TestSingleton:
  @classmethod
  def run(self):
    s1 = Singleton()
    s1.valore = 42
    
    s2 = Singleton()
    print(f"Valore di s2: {s2.valore}")  # 42
    if s1 is s2:
        print("s1 e s2 puntano alla stessa istanza")
