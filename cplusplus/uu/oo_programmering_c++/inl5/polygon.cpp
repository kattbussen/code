#include "polygon.h"

Polygon::Polygon() {
	numberOfVertices = 0;
	vertArray = 0;
}

Polygon::Polygon(int x, int y, Vertex *vertArr, int noVertices) {
	vert = Vertex(x,y);
	numberOfVertices = noVertices;

	vertArray = new Vertex[noVertices];
	for(int i = 0; i < noVertices; i++) {
		vertArray[i] = vertArr[i];
	}
}

Polygon::~Polygon() {
	delete[] vertArray;
}

Polygon::Polygon(const Polygon &p) {
	if(this != &p) {
		vert = p.vert;
		numberOfVertices = p.numberOfVertices;
		vertArray = new Vertex[numberOfVertices];
		for(int i = 0; i < numberOfVertices; i++) {
			vertArray[i] = p.vertArray[i];
		}
  }
}
void Polygon::add(Vertex ver) {
  Vertex *tmpArray = new Vertex[numberOfVertices+1];
  for(int i = 0; i < numberOfVertices; i++) {
  	tmpArray[i] = vertArray[i];
	}

  delete[] vertArray;
  tmpArray[numberOfVertices] = ver;
  numberOfVertices++;
  vertArray = tmpArray;
}


int Polygon::area() {
	int sum = 0;
	for(int i = 0; i < numberOfVertices-1; i++) {
		int first = vertArray[i].getXpos() * vertArray[i+1].getYpos();
		int second = vertArray[i+1].getXpos() * vertArray[i].getYpos(); 
		sum += (first - second) / 2;
	}
	if(numberOfVertices > 0) {
		int first = vertArray[numberOfVertices].getXpos() * vertArray[0].getYpos();
		int second = vertArray[0].getXpos() * vertArray[numberOfVertices].getYpos();
		sum += (first - second) / 2;
	}	

	return std::abs(sum);
}

void Polygon::print() {
	std::cout << "POLYGON: (" << vert.getXpos() << "," << vert.getYpos() << ") { ";
	for(int i = 0; i < numberOfVertices; i++) {
		std::cout << "(" << vertArray[i].getXpos() << "," << vertArray[i].getYpos() << ") ";	
	}
	std::cout << "}" << std::endl; 
}	

Polygon* Polygon::clone() const {
	Polygon* poly = new Polygon(*this);
	return poly;
}

std::string Polygon::extractInfo() {
	std::string tmp = "";
	tmp = "POLYGON: (" + std::to_string(vert.getXpos()) + "," + std::to_string(vert.getYpos()) +  ") { ";
	for(int i = 0; i < numberOfVertices; i++) {
		tmp += "(" + std::to_string(vertArray[i].getXpos()) + "," + std::to_string(vertArray[i].getYpos()) + ") ";	
	}
	tmp += "}"; 
	
	return tmp;
}

std::istream& Polygon::read(std::istream &input) {
	int x, y, vertX, vertY;
  std::string substring;

  input >> substring;    
  x = std::stoi(substring.substr(1, substring.find(',')));
  y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));

  //read the first vertice
  input >> substring;
  input >> substring;
  vertX = std::stoi(substring.substr(1, substring.find(',')));
  vertY = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
  Vertex varr[1] = { Vertex(vertX, vertY) };
  Polygon *poly = new Polygon(x, y, varr, 1); 
    
  //read additional vertices
  input >> substring;
	while(substring != "}") {
		vertX = std::stoi(substring.substr(1, substring.find(',')));
    vertY = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
    add(Vertex(vertX,vertY));
    input >> substring;
	}   
   
	vert = Vertex(x,y);

	//vertArray = new Vertex[noVertices];
	//for(int i = 0; i < noVertices; i++) {
	//	vertArray[i] = vertArr[i];
	//}

  return input;
}
