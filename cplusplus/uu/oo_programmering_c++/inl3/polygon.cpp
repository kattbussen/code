#ifndef POLYGON_H
#define POLYGON_H
#include "polygon.h"
#endif

Polygon::Polygon(double x, double y, Vertex *vertArr, int noVertices)
{
	vert = Vertex(x,y);
	numberOfVertices = noVertices;

	vertArray = new Vertex[noVertices];
	for(int i = 0; i < noVertices; i++)
		vertArray[i] = vertArr[i];
}

Polygon::~Polygon()
{
	delete[] vertArray;
}

Polygon::Polygon(const Polygon &p)
{
	if(this != &p)
	{
		vert = p.vert;
		numberOfVertices = p.numberOfVertices;
		vertArray = new Vertex[numberOfVertices];
		for(int i = 0; i < numberOfVertices; i++)
			vertArray[i] = p.vertArray[i];
  }
}

double Polygon::area()
{
	double sum = 0;
	for(int i = 0; i < numberOfVertices-1; i++)
	{
		double first = vertArray[i].getXpos() * vertArray[i+1].getYpos();
		double second = vertArray[i+1].getXpos() * vertArray[i].getYpos(); 
		sum += (first - second) / 2;
	}
	if(numberOfVertices > 0)
	{
		double first = vertArray[numberOfVertices].getXpos() * vertArray[0].getYpos();
		double second = vertArray[0].getXpos() * vertArray[numberOfVertices].getYpos();
		sum += (first - second) / 2;
	}	

	return std::abs(sum);
}

void Polygon::print()
{
	std::cout << "type: Polygon" << std::endl;
	std::cout << "x: " << getX() << std::endl;
	std::cout << "y: " << getY() << std::endl;
	std::cout << "size: " << area() << std::endl;
}

/*int main()
{
	double x = 3;
	double y = 5;

	Vertex varr[4];
  varr[0] = Vertex(0,0); 
  varr[1] = Vertex(10,0);
  varr[2] = Vertex(5,2);
  varr[3] = Vertex(5,5);

	Polygon p = Polygon(x, y, varr, 4);
	p.print();
	
	Polygon p2 = p;
	p2.print();

	Polygon p3 = p2;
	p3.print();

	return 0;
}*/