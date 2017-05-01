#include <iostream>

// Functions 

// Functions can have any number of arguments
int add(int a, int b, int c)
{
  return a + b + c;
}

// Functions don't have to return a value (we say they return `void`)
void printGreeting(std::string name)
{
  std::cout << "Hello, " << name << "!" << std::endl;
  // No return statement
}

// Functions can modify their arguments, but the changes won't be visible outside!
void incrementBad(int variable)
{
  variable = variable + 1;
  std::cout << "Inside incrementBad, the variable is: " << variable << std::endl;
}

// To modify the arguments to a function we need to pass them by reference
void incrementGood(int& variable)
{
  variable = variable + 1;
}

int main()
{
  int result = add(1, 2, 3); // result is 6

  printGreeting("world");

  int a = 0;
  incrementBad(a);
  std::cout << "After incrementBad, the variable is: " << a << std::endl;

  incrementGood(a);
  std::cout << "After incrementGood, the variable is: " << a << std::endl;
}
