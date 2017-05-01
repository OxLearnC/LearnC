#include <iostream>

// Modified version of Program6.cpp using a function!

// Function definition
// Note that we need to declare the return type of the function
// As well as the type of its arguments
double celsiusToFahrenheit(double celsius)
{
  double fahrenheit;
  fahrenheit = 32 + celsius * 9.0 / 5.0;
  return fahrenheit;
  // or alternatively:
  // return 32 + celsius * 9.0 / 5.0
}

int main()
{
  std::cout << "Celsius to Fahrenheit table!" << std::endl;

  std::cout << "Celsius\tFahrenheit" << std::endl;

  for (int i = 0; i < 10; i++) {
    double celsius = 10 * i;

    std::cout << celsius << '\t' << celsiusToFahrenheit(celsius) << std::endl;
  }

  return 0;
}
