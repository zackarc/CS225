// Your code here! :)
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

#include <string>

class student{
public:
	student();
	string getName();
	int getGrade();
	void setName(string newname);
	void setGrade(int newgrade);

private:
	string name;
	int grade;
};
#endif
