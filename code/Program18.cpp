#include <iostream>
#include <vector>

void example()
{
    int a = 1;
    int* ptr; // We don't have to initialize this straight away!

    ptr = &a; // The operator & is used to obtain a pointer to some variable

    a = 10;
    std::cout << *ptr << std::endl; // prints 10
    // The operator * is used to obtain the value that a pointer points to
    // This is called "dereferencing" the pointer

    *ptr = 0;
    std::cout << a << std::endl; // prints 0

    // Unlike references, we can create a vector that contains pointers!
    std::vector<int*> vec; // No problem!
    int e1;
    int e2;
    vec.push_back(&e1);
    vec.push_back(&e2);

    // We can also easily change what a pointer points to!
    ptr = &e1; // Now ptr points to e1
    ptr = &e2; // Now ptr points to e2
    
    // What would happen if I dereference a pointer that hasn't been initialized??
    int* anotherPtr;
    std::cout << *anotherPtr << std::endl;
}

// You can take pointers to anything, including vectors!
void incrementAllElements(std::vector<int>* vec)
{
    for (int i = 0; i < (*vec).size(); i++) {
        (*vec)[i] = (*vec)[i] + 1;
    }
}

int main()
{
   example();
}
