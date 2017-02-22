// animal.cpp
#include "animal.h"
#include <string>
#include <iostream>

using namespace std;

animal::animal(){
	this->type = "cat";
	this->food = "fish";
}

animal::animal(string type, string food){
	this->type = type;
	this->food = food;
}

string animal::getType(){
	return this->type;
}
void animal::setType(string newType){
	this->type = newType;
}

string animal::getFood(){
	return this->food;
}

void animal::setFood(string newFood){
	this->food = newFood;
}

void animal::print(){
	cout << "I am a " << this->getType() << endl;
}
