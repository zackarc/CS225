// Your code here
#include <iostream>
#include <string>
#include "food.h"

using namespace std;

void increaseQuantity(food * f);

int main(){
	food * f = new food;
	f->setName("apple");
	cout << "The quantity of " << f->getName() << " is now " << f->getQuantity() << "." << endl;
	increaseQuantity(f);
	cout << "The quantity of " << f->getName() << " is now " << f->getQuantity() << "." << endl;
	delete f;
	f = NULL;
	return 0;
}

void increaseQuantity(food * f){
	f->setQuantity(f->getQuantity() + 1);
}
