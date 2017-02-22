#include <iostream>
#include <string>
#include "square.h"
using namespace std;

int main(){
    Square a;
    Square b = a;
    Square c(a);
    return 0;
}
// We need assignment operator because of the rule of big three, which means
// if we write copy constructor, destructor, we need to overload assignment operator
