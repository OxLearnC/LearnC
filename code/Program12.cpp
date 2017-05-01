#include <iostream>

struct Complex
{
  double realPart;
  double imaginaryPart;
};

Complex sum(Complex left, Complex right)
{
  Complex result;
  result.realPart = left.realPart + right.realPart;
  result.imaginaryPart = left.imaginaryPart + right.imaginaryPart;
}

void printComplex(Complex c)
{
  std::cout << c.realPart << " + " << c.imaginaryPart << "i";
}

// Challenge: implement complex subtraction, multiplication and division!

int main()
{
  Complex z;
  z.realPart = 10.0;
  z.imaginaryPart = 5.0;
}
