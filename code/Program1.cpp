// C++ is a modular language, many of its features are located in external packages
// We need to tell the compiler we will be using the console output functions, which
// are located in the `iostream` package
#include <iostream>

// This is the main function, every C++ program has one and they all look like this
// When we run our program, this is the function that will be called!
int main()
{
  // This is a comment! The compiler will ignore these

  // `std::cout` stands for the "standard output" (i.e. text output to the console)
  // The operator `<<` prints some data to an output
  std::cout << "Hello, World!";

  // `std::endl` is how C++ calls the end-of-line character
  // You can also use '\n';
  std::cout << std::endl;
  //std::cout << '\n';

  // By convention, the main function returns 0 if everything went ok, and some other number
  // if there was an error.
  return 0;
}
