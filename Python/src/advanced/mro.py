# Method Resolution Order
class A:
  def method(self):
    print("Metodo di A L0")
class B(A):
  def method(self):
    print("Metodo di B L1")
    super().method() 
class C(A):
  def method(self):
    print("Metodo di C L1")
    super().method() 
class D(B, C):
  def method(self):
    print("Metodo di D L2")
    B.method(self)  # evito ambiguità con chiamata diretta
    C.method(self) 
    print("Metodo chiamata super(), precedenza ereditarietà sinistra") 
    super().method() 

class TestMRO:
  @classmethod
  def run(cls):
    d = D()
    d.method()