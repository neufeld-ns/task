#include "Factory.h"
#include <iostream>
#include <stdio.h>
#include <vector>

int main()
{

	Container<Shape> &shapesContainer = Container<Shape>();
	try
	{
		shapesContainer.pop_front();
	}
	catch (const EmptyContainerException &e)
	{
		std::cout << e.what();
	}
	GenerateShapes(shapesContainer, 20);
	std::cout << Shape::getCount()<< std::endl;
	Container<Shape>::CIterator it = shapesContainer.begin();
	for (; it != shapesContainer.end(); ++it)
	{
		std:: cout <<(*it)->print();
		std::cout << std::endl;
	}
	shapesContainer.clear();
	std::cout << Shape::getCount();

	return 0;
}