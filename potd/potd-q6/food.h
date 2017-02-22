// Your code here
#ifndef FOOD_H
#define FOOD_H

#include <string>

using namespace std;

class food{
public:
	food();
	string getName();
	int getQuantity();
	void setName(string newName);
	void setQuantity(int newQuantity);

private:
	string name;
	int quantity;
};

#endif
