#include <iostream>
#include <vector>

void printVector(std::vector<int> v)
{
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << ", ";
  }
  std::cout << std::endl;
}

void incrementAll(std::vector<int> v)
{
  for (int i = 0; i < v.size(); i++) {
    v[i] ++;
  }
}  

int main()
{
  // Vectors are a generic type: you can have std::vector<int>, std::vector<double>...
  std::vector<int> numbers;

  numbers.push_back(1); // Add elements at the back
  numbers.push_back(2);
  printVector(numbers);

  // You can also insert elements at any position
  // But you can't select the position by number, you have to write vector.begin() + i
  numbers.insert(numbers.begin() + 1, 100);
  printVector(numbers);

  // We can access the elements of a vector using square brackets
  std::cout << numbers[0] << std::endl;

  // We can also modify them!
  numbers[0] = 27;
  std::cout << numbers[0] << std::endl;

  // Vectors are copied when you pass them to a function, so incrementAll actually does nothing!
  printVector(numbers);
  incrementAll(numbers);
  printVector(numbers);
  // You need to use references if you want to write an incrementAll that actually works
  // Also, passing vectors to functions is relatively slow, it's better to pass them as references

  return 0;
}
