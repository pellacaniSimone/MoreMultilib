#include "factory.h"

static void drawCircle(Shape* this) {
  (void)this;
  printf("Drawing an empty Circle\n ");
  const int dim = 10;
  const float radius = dim / 2.0f;
  const float center = radius - 0.5f;
  const float border_thickness = 0.5f;
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++) {
      float dist = sqrt(pow(i - center, 2) + pow(j - center, 2));
      if (dist >= radius - border_thickness && dist <= radius + border_thickness)
        printf(" #");
      else
        printf("  ");
    }
    printf("\n");
  }
}

static void drawSquare(Shape* this) {
  (void)this;
  printf("Drawing a empty Square\n");
  const int dim = 10;
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++)
      if (i == 0 || i == dim - 1 || j == 0 || j == dim - 1) printf(" #") ;
      else printf("  ") ;
    printf("\n") ;
  }
}

static  Shape* createCircle() {
  Circle* circle = (Circle*)malloc(sizeof(Circle));
  circle->base.draw = drawCircle;
  circle->radius = 5;
  return (Shape*)circle;
}

static  Shape* createSquare() {
  Square* square = (Square*)malloc(sizeof(Square));
  square->base.draw = drawSquare;
  square->side = 10;
  return (Shape*)square;
}

// pattern factory function
static  Shape* ShapeFactory(const char* shapeType) {
  if (strcmp(shapeType, "circle") == 0) {
    return createCircle();
  } else if (strcmp(shapeType, "square") == 0) {
    return createSquare();
  } else {
    printf("Tipo di forma non supportato.\n");
    return NULL;
  }
}

static void destroyShape(Shape* shape) {  free(shape); }

void  factory_example() {
  Shape* shape1 = ShapeFactory("circle");
  if (shape1 != NULL) {
    shape1->draw(shape1);
    destroyShape(shape1);
  }

  Shape* shape2 = ShapeFactory("square");
  if (shape2 != NULL) {
    shape2->draw(shape2);
    destroyShape(shape2);
  }

  Shape* shape3 = ShapeFactory("triangle");  // Tipo non supportato
  if (shape3 != NULL) {
    shape3->draw(shape3); // noting to do
    destroyShape(shape3);
  }
}
