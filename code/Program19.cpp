#include <iostream>
#include <vector>

void printVector(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
    {
		std::cout << vec[i] << ", ";
    }
	std::cout << std::endl;
}

std::vector<int>* getPointer()
{
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);

	return &vec; // vec is destroyed here, but a pointer to it still survives!
}

int main()
{
	std::vector<int>* vec = getPointer();
	printVector(*vec); // What will happen here?
	return 0;
}
