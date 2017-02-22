// Your code here! :)
#include "student.h"

using namespace std;

student::student(){
	name = "default name";
	grade = 1;
}

string student::getName(){
	return name;
}

int student::getGrade(){
	return grade;
}
void student::setName(string newname){
	this->name = newname;
}
void student::setGrade(int newgrade){
	this->grade = newgrade;
}
