// square.cpp
#include "square.h"
#include <string>
#include <iostream>

using namespace std;

square::square(){
	this->name = "mysquare";
	this->length = new double(2.0);
}

square::square(const square & orig){
	cout << "I am copying!" << endl;
	name = orig.name;
	length = new double;
	*(length) = *(orig.length);
}

square::~square(){
	delete length;
	length = NULL;
}
