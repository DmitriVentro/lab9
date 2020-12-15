#pragma once
#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1.0); //Число Пи 
// Родительский класс
class Figure 
{
public:
	Figure();
	virtual ~Figure();
	virtual void show() = 0;
	virtual double calcArea() = 0;
    virtual Figure* copy() = 0;
};
//Дочерний класс Круг
class Circle : public Figure
{
public:
	Circle();
	Circle(int);
	virtual ~Circle();
	virtual void show();
	virtual double calcArea();
    virtual Figure* copy();
	int get_R();// геттер
private:
	int *r;
};
//Дочерний класс Прямоугольник
class Rectangle : public Figure
{
public:
	Rectangle();
	Rectangle(int, int);
	virtual ~Rectangle();
	virtual void show();
	virtual double calcArea();
    virtual Figure* copy();
	int get_A();// геттер
	int get_B();// геттер

private:
	int *a, *b;
};
//Дочерний класс Треугольник
class Triangle : public Figure
{
public:
	Triangle();
	Triangle(int, int, int);
	virtual ~Triangle();
	virtual void show();
	virtual double calcArea();
	int get_A();// геттер
	int get_B();// геттер
	int get_C();// геттер
private:
	int *a, *b, *c;
};

class Cylinder 
{
public:
    Cylinder(Figure *, double);
    ~Cylinder();
    double calcVolume();
    void show();
private:
    Figure *F;
    double *H;
};

Cylinder::Cylinder(Figure *F1, double H1)
{
    // F = F
}

// Функция для подсчёта объема
double volumeFigure(Figure *F, int h);

Figure::Figure() { cout << "Вызван конструктор Figure();"; }
Figure::~Figure() { cout << "Вызван деструктор ~Figure();"; }

Circle::Circle() : Figure()
{
	cout << "Вызван конструктор Circle() : Figure();";
	r = new int;
}

Circle::Circle(int r1) : Figure()
{
	cout << "Вызван конструктор Circle(int r1) : Figure();";
	r = new int;
	*r = r1;
	cout << &r << endl;
}

Circle::~Circle()
{
	delete r;
}

int Circle::get_R()
{
	return *r;
}
void Circle::show()
{
	cout << "circleInfo:\n r - " << *r << endl;
}
double Circle::calcArea()
{
	return PI * pow(*r, 2);
}

Figure *Circle::copy()
{
    Figure *C = new Circle(*r);
    return C;
}

Rectangle::Rectangle() : Figure()
{
	cout << "Вызван конструктор Circle() : Figure();";
	a = new int;
	b = new int;
}

Rectangle::Rectangle(int a1, int b1) : Figure()
{
	cout << "Вызван конструктор Circle(int r1) : Figure();";
	a = new int;
	b = new int;
	*a = a1;
	*b = b1;
}

Rectangle::~Rectangle()
{
	delete a, b;
}

void Rectangle::show()
{
	cout << "rectangleInfo:"
		 << "\n a - " << *a << "\n b - " << *b << endl;
}
double Rectangle::calcArea()
{
	return *a * *b;
}

int Rectangle::get_A()
{
	return *a;
}

int Rectangle::get_B()
{
	return *b;
}

Figure *Rectangle::copy()
{
    Figure *rec = new Rectangle(*a, *b);
    return rec;
}

double volumeFigure(Figure *F, int h)
{
	return F->calcArea() * h;
}

Triangle::Triangle() : Figure()
{
	a = new int;
	b = new int;
}

Triangle::Triangle(int a1, int b1, int c1) : Figure()
{
	a = new int;
	b = new int;
	c = new int;
	*a = a1;
	*b = b1;
	*c = c1;
}

void Triangle::show()
{
	cout << "TriangleInfo:"
		 << "\n a - " << *a << "\n b - " << *b << "\n c - " << *c << endl;
}

double Triangle::calcArea()
{
	double P;
	P = (*a + *b) / 2;
	return sqrt(P * (P - *a) * (P - *b) * (P - *c));
}

int Triangle::get_A()
{
	return *a;
}
int Triangle::get_B()
{
	return *b;
}
int Triangle::get_C()
{
	return *c;
}

Triangle::~Triangle()
{
	delete a, b, c;
}

double Cylinder::calcVolume()
{
    return F->calcArea() * *H;
}

void Cylinder::show()
{
    std::cout << "Цилиндр:\n";
    std::cout << "H - " << *H;
    std::cout <<"\nПро основание: \n";
    F->show();
}

Cylinder::~Cylinder()
{
    delete F, H;
}