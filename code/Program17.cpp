#include <iostream>
#include <vector>

void example()
{
    int a = 1;
    int &b = a;
    // b is now a reference to a
    // Whatever changes we make to either of them will also affect the other

    a = 10;
    std::cout << b << std::endl; // prints 10

    b = 0;
    std::cout << a << std::endl; // prints 0

    // references are a bit different from normal variables!
    // For example, we can't leave them uninitialized
    int &c; // this will not compile correctly!

    // We also can't create a vector that contains references
    std::vector<int&> vec; // this won't compile!

    // There is also no way of changing what variable b references!
}

// This doesn't work properly because its parameter is copied
void incrementAllElementsBad(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = vec[i] + 1;
    }
}

// This does work because the parameter is passed as a reference!
void incrementAllElements(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = vec[i] + 1;
    }
}

int main()
{
    example();
}
