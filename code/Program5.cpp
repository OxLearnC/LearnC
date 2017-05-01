#include <iostream>
#include <string>

int main()
{
  std::cout << "Celsius to Fahrenheit converter!" << std::endl;

  std::cout << "What is the input? (celsius/fahrenheit): ";

  std::string inputType;
  std::cin >> inputType;

  std::cout << "Input a temperature in " << inputType << ": ";

  double temperature;
  std::cin >> temperature;

  // We compare things using `==` because `=` means assignment
  // Confusing them is a very easy mistake to make!
  if (inputType == "fahrenheit") {
    // FILL THIS IN!
  } else if (inputType == "celsius") {
    // FILL THIS IN!
  } else {
    // FILL THIS IN!
  }

  return 0;
}
