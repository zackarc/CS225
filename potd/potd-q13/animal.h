// animal.h
#include <string>

using namespace std;

class animal{
public:
	animal();
	animal(string type, string food);
	string getType();
	void setType(string newType);
	string getFood();
	void setFood(string newFood);
	virtual void print();
private:
	string type;
protected:
	string food;
};
