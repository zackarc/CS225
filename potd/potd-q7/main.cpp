// Your code here! :)
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

void graduate(student &s);

int main(){
	student s;
	s.setName("Sally");
	s.setGrade(5);
	cout << s.getName() << " is in grade " << s.getGrade() << "." << endl;
	graduate(s);
	cout << s.getName() << " is in grade " << s.getGrade() << "." << endl;
	return 0;
}

void graduate(student &s){
	s.setGrade(s.getGrade() + 1);
}
