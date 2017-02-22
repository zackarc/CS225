#ifndef _SQUARE_H
#define _SQUARE_H

using namespace std;

class Square {
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
        // We need assignment operator because of the rule of big three, which means
        // if we write copy constructor, destructor, we need to overload assignment operator
        Square & operator=(const Square & rhs);
        Square & operator+(const Square & rhs);
};

#endif
