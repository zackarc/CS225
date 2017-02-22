#include <iostream>
#include <string>
using namespace std;

#include "square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName) {
  name = newName;
}

void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}

// We need assignment operator because of the rule of big three, which means
// if we write copy constructor, destructor, we need to overload assignment operator
Square & Square::operator=(const Square & rhs){
    if (this != &rhs){
        this->name = rhs.name;
        delete lengthptr;
        this->lengthptr = rhs.lengthptr;
    }
    return *this;
}

Square & Square::operator+(const Square & rhs){
    Square * newSquare = new Square();
    newSquare->name = this->name + rhs.name;
    *(newSquare->lengthptr) = *(this->lengthptr) + *(rhs.lengthptr);
    return * newSquare;
}
