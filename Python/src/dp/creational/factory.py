
import math


class Shape:
  def draw(self):
    raise NotImplementedError("Il metodo draw() deve essere implementato dalle sottoclassi")

class Circle(Shape):
  def draw(self):
    print("Drawing a Circle")
    dim = 10
    radius = dim / 2.0
    center = radius - 0.5
    for i in range(dim):
      for j in range(dim):
        dist = math.sqrt((i - center) ** 2 + (j - center) ** 2)
        if dist <= radius:
          print(" #", end="")
        else:
          print("  ", end="")
      print()

class Square(Shape):
  def draw(self):
    print("Drawing a full Square")
    dim = 10
    for _ in range(dim):
      print(" #" * dim)

class ShapeFactory:
    @staticmethod
    def create_shape(shape_type):
      """La classe da creare si sceglie a runtime, ==> è pattern factory"""
      if shape_type == "circle":
        return Circle()
      elif shape_type == "square":
        return Square()
      else:
        print("Tipo di forma non supportato.")
        return None

class TestShapeFactory:
  @classmethod
  def run(cls):
    shape1 = ShapeFactory.create_shape("circle")
    if shape1:
      shape1.draw()
    print()  # Spazio per separare le forme
    shape2 = ShapeFactory.create_shape("square")
    if shape2:
      shape2.draw()
    print()  # Spazio per separare le forme
    shape3 = ShapeFactory.create_shape("triangle")
    if shape3:
      shape3.draw()