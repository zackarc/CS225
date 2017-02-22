// square.h
#include <string>

using namespace std;

class square{
public:
	square();
	square(const square & orig);
	~square();
private:
	double * length;
	string name;
};
