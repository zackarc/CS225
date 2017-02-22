// main.cpp
#include <iostream>
#include <string>
#include "animal.h"
#include "pet.h"

using namespace std;

int main() {
	animal a;
	a.print();
	pet b("cat","fish","Garfield","Jon");
	b.print();
	return 0;
}
