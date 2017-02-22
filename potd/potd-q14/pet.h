// pet.h
#include <string>
#include "animal.h"

using namespace std;

class pet : public animal{
public:
	pet();
	pet(string t, string f, string n, string o);

	string getFood();
	void setFood(string f);
	string getName();
    void setName(string n);
	string getOwnerName();
	void setOwnerName(string o);
	void print();

private:
	string name;
	string owner_name;
};
