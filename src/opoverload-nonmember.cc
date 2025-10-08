#include <iostream>

// class example
class Rational {
    int num, den;
    public:
    // constructors
    Rational(int n, int d) {
        num=n;  den=d;
    }
    
    Rational() {
        num = 0;  den = 1;
    }

  // prints the object on output stream <str>
  void print(std::ostream & str) const;
};

std::ostream & operator << (std::ostream & st, const Rational & r) {
  r.print(st);
  return st;
}

// modify the function to actually implement addition in the simple case when the denominators of the two arguments are the same.
// What do you need to achieve this?
Rational operator + (const Rational & a, const Rational & b) {
  std::cout << "non-member + on Rational" << std::endl;
  return Rational();  // not performing anything useful
}

void Rational::print(std::ostream & str) const {
  str << num << "/" << den << std::endl;
}



int main() {
  Rational r1(1,2), r2(2,3), r3;
  std::cout << "calling non-member operator +" << std::endl;
  r3 = r1+r2;

  /*std::cout << "operator called like a function" << std::endl;
    operator+(r1, r2); */

  //r3.print(std::cout);
  std::cout << r3;

  return 0;
}
