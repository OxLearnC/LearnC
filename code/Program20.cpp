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
    std::vector<int>* vec = new std::vector<int>;
    (*vec).push_back(0);
    (*vec).push_back(1);
    vec->push_back(2); // a->b is a convenient shorthand for (*a).b

    return vec; // vec now lives in the central storage so it will not be destroyed here!
}

int main()
{
    std::vector<int>* vec = getPointer();
    printVector(*vec); // This is fine now!

    delete vec;

    // This is NOT fine! We are using vec after deleting it!
    printVector(*vec);

    // This is also NOT fine! We are deleting vec twice!
    delete vec;

    return 0;
}
