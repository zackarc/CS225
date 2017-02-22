#include <iostream>
using namespace std;

#include "square.h"
#include <string>

int main() {
    square b;
    square c;
    square a(b);
    square * d = new square(c);
    return 0;
}
