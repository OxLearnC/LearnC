#include <iostream>

int main()
{
  std::cout << "Celsius to Fahrenheit converter!" << std::endl;

  std::cout << "Input a temperature in Celsius: ";

  double celsius;
  std::cin >> celsius;

  // We declare the variable and initialize it at the same time!
  double fahrenheit = 32 + celsius * 9.0 / 5.0;

  std::cout << celsius
            << " degrees celsius is "
            << fahrenheit
            << " degrees fahrenheit\n";
  
  return 0;
}
