#include <iostream>

// class example
// overload the addition (+)
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

  // prints the rational on <str> 
  void print(std::ostream & str) const;

  Rational operator + (const Rational & r);

  const Rational & operator= (const Rational & r) {
    std::cout << "Assignment operator with ";
    //r.print(std::cout);
    num = r.num;
    den = r.den;
    return r;
  }
};

Rational Rational::operator + (const Rational & r) {
  Rational result;

  if (den == r.den) {
    result.num = num+r.num;
    result.den = den;
  }
  std::cout << "member + on Rational" << std::endl;
  return result;  // not performing anything useful
}

void Rational::print(std::ostream & str) {
  str << num << "/" << den << std::endl;
}


int main() {
  Rational r1(1,2), r2(3,7), r3;
  // std::cout << "operator syntax call" << std::endl;
  r3=r1+r2;
  r3.print(std::cout);

  /*std::cout << "operator called like a function" << std::endl;
    r1.operator+(r2);*/

  return 0;
}
