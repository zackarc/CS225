// Your code here
#include <string>
#include "food.h"

using namespace std;

food::food(){
	name = "default food";
	quantity = 0;
}

string food::getName(){
	return name;
}

int food::getQuantity(){
	return quantity;
}

void food::setName(string newName){
	this->name = newName;
}

void food::setQuantity(int newQuantity){
	this->quantity = newQuantity;
}
