#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
	Shape() {};
	virtual double area() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape
{
private:
	double r;
public:

	Circle(double radius) : r(radius) {}
	double area()
	{
		return 3.14 * r * r;
	}
};

class Rectangle : public Shape
{
protected:
	double side_a, side_b;
public:
	Rectangle(double a, double b) : side_a(a), side_b(b) {}
	double area()
	{
		return side_a * side_b;
	}
};

class Square : public Rectangle
{
public:
	Square(double side) : Rectangle(side, side) {}
};


int main()
{
	Shape** array = new Shape * [3];
	array[0] = new Circle(2.25);
	array[1] = new Rectangle(3, 5);
	array[2] = new Square(9);

	for (int i = 0; i < 3; i++)
	{
		array[i]->area();
	}

	delete array[0];
	delete array[1];
	delete array[2];
	delete[] array;


	system("pause");
	return 0;
}