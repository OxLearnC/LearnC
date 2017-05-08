#include <iostream>
#include <vector>

std::vector<int> removeDuplicates(std::vector<int> vec)
{
    std::vector<int> result; // We are going to use a new vector to store the result without duplicates

    // The algorithm we will follow:
    // 1. For each element in vec, check if it is in result
    // 2. If it is not, then add it at the end of result

    for (int i = 0; i < vec.size(); i++) {
	bool found = false;
	for (int j = 0; j < result.size(); j++) {
	    if (result[j] == vec[i]) {}
	    // Fill this in!
	}
    }
    if (!found) {
	// And this!
    }
}

return result;
}

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    vec = removeDuplicates(vec); 

    for (int i = 0; i < vec.size(); i++) {
	std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;
    // The output should be "1, 2, 5"
}
