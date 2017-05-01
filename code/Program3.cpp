#include <iostream>

int main()
{
  // C++ has a few types defined by default

  std::cout << "INTEGERS" << std::endl;
  int a; // The `int` type represents integers (positive or negative, no decimals!)

  a = 1; // This sets the value of `a` to 1
  std::cout << "a is: " << a << std::endl; // We can print numbers just like strings!

  a = 2.2; // Careful with this!
  std::cout << "a should be 2.2 but is: " << a << std::endl; 

  // You can also use variables in expressions
  a = a + 17 - a * a;
  std::cout << "a is now: " << a << std::endl;

  // Arithmetic operators are also ok:
  a = 10 * 3 - 5;
  std::cout << "10 * 3 - 5 is: " << a << std::endl;

  // Division is rounded down
  a = 10 / 3;
  std::cout << "10 / 3 is: " << a << std::endl;

  std::cout << std::endl << "DOUBLES" << std::endl;
  double d; // The `double` type represents decimal numbers (`double` stands for double-precision)
  // The same operations are available for decimal numbers!
  d = 1.47; 
  std::cout << "d is: " << d << std::endl;
  d = 1.5 * 3 - 5.4 / 7.2;
  std::cout << "1.5 * 3 - 5.4 / 7.2 is: " << d << std::endl;
  d = 10 / 3; // Very careful with this!
  std::cout << "10 / 3 is: " << d << std::endl;

  std::cout << std::endl << "BOOLEANS" << std::endl;
  bool b; // A `bool` variable can be `true` or `false`
  b = true;
  // When printed, bools look like integers!
  std::cout << "true is " << b << std::endl;

  // Logical operations: and, or, not
  b = true && (false || ! false);
  std::cout << "true && (false || !false) is " << b << std::endl;

  // You can also compare elements of other types to get a `bool`
  b = (1 == 3); // false
  std::cout << "1 == 3 is " << b << std::endl;
  b = (1 == 1); // true
  std::cout << "1 == 1 is " << b << std::endl;
  return 0;
}
