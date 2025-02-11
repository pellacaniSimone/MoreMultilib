#include "factory.h"




void Circle::draw() const  {
  cout << "Drawing a Circle" << endl;
  const int dim = 10; // imposta la dimensione del diametro
  const float radius = dim / 2.0f; // calcola il raggio
  const float center = radius - 0.5f; // posizione del centro
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++) {
      float dist = sqrt(pow(i - center, 2) + pow(j - center, 2)); // distanza dal centro
      if(dist <= radius)
        cout << " #"; // punto all'interno del cerchio
      else
        cout << "  "; // punto all'esterno del cerchio
    }
    cout << endl;
  }
}


void Square::draw() const  {
  cout << "Drawing a full Square" << endl;
  const int dim = 10;
  for(int i = 0; i < dim; i++) // stampa un'intera riga e va a capo
  {
    for(int j = 0; j < dim; j++) // stampa i caratteri che compongono la riga
      cout<<" #" ;
    cout<<endl ;  // vai a capo a fine riga
  }
}



// costruttore statico per creare una forma basata sul tipo passato come parametro
unique_ptr<Shape> ShapeFactory::createShape(const string& shapeType) {
  if (shapeType == "circle") {
    return make_unique<Circle>();
  } else if (shapeType == "square") {
    return make_unique<Square>();
  } else {
    cout << "Tipo di forma non supportato." << endl;
    return nullptr;
  }
}


void factory_example() {
  // Utilizza il Factory Pattern per creare una forma di tipo Circle
  unique_ptr<Shape> shape1 = ShapeFactory::createShape("circle");
  if (shape1) { shape1->draw(); } // Stampa "Drawing a Circle"
  // Utilizza il Factory Pattern per creare una forma di tipo Square
  unique_ptr<Shape> shape2 = ShapeFactory::createShape("square");
  if (shape2) {shape2->draw();} // Stampa "Drawing a Square"
  // Prova a creare una forma non supportata
  unique_ptr<Shape> shape3 = ShapeFactory::createShape("triangle");  // Tipo non supportato
  if (shape3) { shape3->draw(); }  // Non verrà chiamato
}
