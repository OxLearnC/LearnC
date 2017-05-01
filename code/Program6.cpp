#include <iostream>

int main()
{
  std::cout << "Celsius to Fahrenheit table!" << std::endl;

  // \t inserts a tab character
  std::cout << "Celsius\tFahrenheit" << std::endl;

  // i++ is the same as (i = i + 1)
  // This is where the name C++ comes from!
  for (int i = 0; i < 10; i++) {
    double celsius = 10 * i;
    double fahrenheit = 32 + celsius * 9.0 / 5.0;

    std::cout << celsius << '\t' << fahrenheit << std::endl;
    
  }

  // Challenge: modify the code so the user can choose how many rows to print!
  // What happens if the user picks a negative number?
  
  // Another challenge: modify the code so the user can choose what the increment in
  // temperature is, i.e. instead of 0, 10, 20...degrees, the user can choose 0, 5, 10, 15...

  return 0;
}
