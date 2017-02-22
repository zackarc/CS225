// pet.cpp
#include "pet.h"
#include <iostream>
#include <string>

using namespace std;

pet::pet(){
	this->setType("cat");
	this->setFood("fish");
	this->setName("Fluffy");
	this->setOwnerName("Cinda");
}

pet::pet(string t, string f, string n, string o){
	this->setType(t);
	this->setFood(f);
	this->setName(n);
	this->setOwnerName(o);
}

string pet::getFood(){
	return animal::getFood();
}

void pet::setFood(string f){
	animal::setFood(f);
}

string pet::getName(){
	return name;
}

void pet::setName(string n){
	name = n;
}

string pet::getOwnerName(){
	return owner_name;
}

void pet::setOwnerName(string o){
	owner_name = o;
}

void pet::print(){
	cout << "My name is " << name << "." << endl;
}
