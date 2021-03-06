#include "shape.h"
#include "point.h"
#include "circle.h"
#include "rectangle.h"
#include "polygon.h"

#ifndef SHAPELIST_H
#define SHAPELIST_H
class ShapeList : public Shape
{
	public:
		ShapeList();
		ShapeList(const ShapeList &shapes);
		~ShapeList();
		ShapeList& operator=(const ShapeList &slist);
		void add(const Shape& s);
		void remove(const Vertex &v);
		double area();
		void print();

	private:
		class Node
		{
			public:
				Node(const Shape &sh)
				{
					shape = sh.clone();
					next = 0;
				}

				~Node()
				{
					delete shape;
				}				

				void setNext(Node *nextNode)
				{
					next = nextNode;
				}
				Shape* shape;
				Node* next;
		};
		
		int noOfElements;
		Node *list;
};
#endif
