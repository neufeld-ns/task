#pragma once
#include "Base.h"
#include "TemplateContainer.h"
class Shape : public Named
{
public:
	Shape() :Named("Shape") 
	{
		count++;
	};
	Shape(std::string s) : Named(s) 
	{
		count++;
	};
	~Shape()
	{
		count--;
	}
	static int getCount()
	{
		return count;
	}
	std::string print() const {
		return Named::print();
	}
private:
	static int count;
};
class Point :public Shape
{
public:
	std::string print() const{
		return Named::print() +" (" + std::to_string(x) + "," + std::to_string(y) + ")" + "\n";
	}
	Point()
	{
		Shape("Point");
	}
	Point(double X, double Y):Shape("Point")
	{
		x = X;
		y = Y;
	}
	Point(const Point& copy) :Shape("Point")
	{
		x = copy.x;
		y = copy.y;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
private:
	double x, y;
};
class Circle :public Shape
{
public:
	std::string print() const {
		return Named::print() + " with center at " + p->print() + "and R=" + std::to_string(r) + "\n";
	}
	Circle(double X = 0, double Y = 0, double R=1) :Shape("Circle")
	{
		p =new Point(X,Y);
		r = R;
	}
	Circle(Point *point, double R = 1):Shape("Circle")
	{
		p = point;
		r = R;
	}
	Circle(const Circle &copy):Shape("Point")
	{
		p = copy.p;
		r = copy.r;
	}
	~Circle()
	{
		delete p;
	}
private:
	Point *p;
	double r;
};
class Rect :public Shape
{
public:
	std::string print() const {
		return Named::print() + " with angles at points \n1." + p1->print()+"2."+p2->print();
	}
	Rect(double X1 = 0, double Y1 = 0, double X2 = 0, double Y2 = 0)
	{
		p1 = new Point(X1, Y1);
		p2 = new Point(X1, Y1);
	}
	Rect(Point *X1, Point *X2,std::string S= "Rect") : p1(X1), p2(X2), Shape(S) {};
	~Rect()
	{
		delete p1;
		delete p2;
	}
private:
	Point *p1, *p2;
};
class Square :public Rect
{
public:
	std::string print()const {
		return Rect::print();
	}
	Square(Point *X, double side): Rect (X, new Point(X->getX()+side,X->getY()+side), "Square")
	{		
	};
	
private:

};
class Polyline :public Shape
{
public:
	std::string print()const {
		std::string s = Named::print() +" with  points \n";
		Container<Point>::CIterator i = Points.begin();
		for (int c = 0; i != Points.end(); ++i, ++c)
			s += std::to_string(c+1) + ") " + (*i)->print();
		return s;
	}
	Polyline(std::string S = "Polyline") :Shape(S) {};
	Polyline(double X, double Y)
	{
		Points.push_back(new Point(X, Y));
	}
	Polyline(Container<Point> input)
	{

		Container<Point>::CIterator i = input.begin();
		for (; i != input.end(); ++i)
			Points.push_back((*i));
		
	}
	~Polyline()
	{
		Points.clear();
	}
			
	void AddPoint(Point * point)
	{
		Points.push_back(point);
	}
private:
	Container<Point> Points;
};
class Polygon :public Polyline
{
public:

	Polygon():Polyline("Polygon")
	{
	}
	Polygon(double X, double Y):Polyline("Polygon")
	{
		Polyline(X,Y);
	}
}; 