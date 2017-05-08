#include <iostream>

class BankAccount
{
public:
    // Everything we define here can be used from "outside"

    // This is a constructor! It will be used to initialize the instances of this class
    BankAccount(std::string owner)
    {
	// `this` is a special variable which only exists inside functions that belong to a class
	// It represents the object that is being currently accessed
	// It is always a pointer!
	this->balance = 0;
	this->owner = owner;
    }

    bool withdraw(int amount)
    {
	if (this->balance >= amount) {
	    this->balance = this->balance - amount;
	    return true;
	} else {
	    return false;
	}
    }
    
    void deposit(int amount)
    {
	this->balance = this->balance + amount;
    }

    void summary()
    {
	std::cout << "Bank account of " << this->owner << std::endl;
	std::cout << "Current balance: " << this->balance << std::endl;
    }
    
protected:
    // Everything we define here can only be used in BankAccount members
    int balance;
    std::string owner;
};

void printBank(std::vector<BankAccount*> &clients)
{
    for (int i = 0; i < clients.size(); i++)
    {
	clients[i]->summary();
    }
}


int main()
{
    // We should ALWAYS use new to create instances of a class
    BankAccount* john_doe = new BankAccount("John Doe");
    BankAccount* jane_doe = new BankAccount("Jane Doe");

    // These are public, so they can be used here
    john_doe->deposit(100);
    john_doe->summary();

    // These are private, so this will fail
    // account->balance = -10000
    // account->owner = "Jane Doe"

    std::vector<BankAccount*> bank;
    bank.push_back(john_doe);
    bank.push_back(jane_doe);
    printBank(bank);

    delete account;
}
