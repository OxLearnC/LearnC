#include <iostream>
// In this example, we will be using strings!
#include <string>

int main()
{
  std::cout << "What's your name? ";

  // This is a variable declaration
  // We use variables to store data that we want to use in more than one place
  // Every variable has a type (in this case std::string)
  std::string name;

  // `std::cin` is like `std::out` but for reading rather than printing
  // `>>` does the opposite of `<<`, i.e. reads instead of writing
  std::cin >> name;

  // C++ is very flexible with the layout! You can spread code across lines in any way you like
  std::cout << "Hello, "
	    << name
	    << std::endl;
      
  return 0;
}
