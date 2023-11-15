#include <iostream>
#include <vector>
using namespace std;

class Shape abstract{
public:
    virtual double area() const = 0;
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius;
    }
};

class RightTriangle : public Shape {
private:
    double base, height;
public:
    RightTriangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

class Trapezoid : public Shape {
private:
    double base1, base2, height;
public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}
    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.insert(shapes.end(), new Rectangle(4, 5));
    shapes.insert(shapes.end(), new Circle(3));
    shapes.insert(shapes.end(), new RightTriangle(3, 4));
    shapes.insert(shapes.end(), new Trapezoid(2, 3, 4));

    for (auto& shape : shapes) {
        cout << "Area: " << shape->area() << endl;
    }

}

