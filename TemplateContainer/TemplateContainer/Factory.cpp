#include "Factory.h"
#include <ctime>
int Shape::count = 0;

Point* randomPoint()
{
	Point *point = new Point(rand() % 100, rand() % 100);
	return point;
}
/*
void GenerateShapes(Container<Shape> &shapesContainer, int n)
{
	srand((int)time(NULL));
	shapesContainer.push_back(randomPoint());
	shapesContainer.push_back(new Circle(randomPoint(), rand() % 100));
	shapesContainer.push_back( new Rect(randomPoint(), randomPoint()) );
	shapesContainer.push_back( new Square(randomPoint(), rand() % 10) );
	Polyline *polyline = new Polygon();
	Polygon *polygon = new Polygon();
	int l;
	l = rand() % 20;
	for (int j = 0; j < l; j++)
		polyline->AddPoint(randomPoint());
	shapesContainer.push_back(polyline);
	l = rand() % 20;
	for (int j = 0; j < l; j++)
		polygon->AddPoint(randomPoint());
	shapesContainer.push_back(polygon);
}/**/
//*
void GenerateShapes(Container<Shape> &shapesContainer, int n)
{
	srand((int)time(NULL));
	for (int i=0; i < n; i++)
	{
		int typeOfShape =  rand() % 6;
		int l;
		switch (typeOfShape)
		{
			case 0:
				shapesContainer.push_back(randomPoint());
				break;
			case 1:
				shapesContainer.push_back(new Circle(randomPoint(), rand() % 100));
				break;
			case 2:
				shapesContainer.push_back(new Rect(randomPoint(), randomPoint()));
				break;
			case 3: shapesContainer.push_back(new Square(randomPoint(), rand() % 10));
				break;
			case 4:
			{
				Polyline *polyline = new Polyline();
				l = 2 + rand() % 10;
				for (int j = 0; j < l; j++)
					polyline->AddPoint(randomPoint());
				shapesContainer.push_back(polyline);
				break;
			}
			case 5:
			{
				Polygon *polygon = new Polygon();
				l = 2 + rand() % 10;
				for (int j = 0; j < l; j++)
					polygon->AddPoint(randomPoint());
				shapesContainer.push_back(polygon);
				break;
			}
		}
	}
}/**/