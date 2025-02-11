#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>    // per unique_ptr
#include <iostream>
#include <cmath> // per la funzione sqrt e pow
#include <string>
using namespace std;

class Shape {
  public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
  public:
    void draw() const override ;
};

class Square : public Shape {
  public:
    void draw() const override;
};

class ShapeFactory {
  public:
    static unique_ptr<Shape> createShape(const string& shapeType);
};

void factory_example();

#endif