#include <iostream>
#include <vector>

class BankAccount
{
public:
    // Public section
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

    virtual bool withdraw(int amount)
    {
	if (this->balance >= amount) {
	    this->balance = this->balance - amount;
	    return true;
	} else {
	    return false;
	}
    }
    
    virtual void deposit(int amount)
    {
	this->balance = this->balance + amount;
    }

    virtual void summary()
    {
	std::cout << "Bank account of " << this->owner << std::endl;
	std::cout << "Current balance: " << this->balance << std::endl;
    }
    
protected:
    // Protected section
    // Everything we define here can only be used in BankAccount members
    int balance;
    std::string owner;
};

// VIP accounts can go negative!
class VIPAccount : public BankAccount
{
public:
    // We need the constructor for VIPAccount to use the constructor for BankAccount
    VIPAccount(std::string owner) : BankAccount(owner)
    {
    }

    virtual bool withdraw(int amount)
    {
	this->balance = this->balance - amount;
	return true;
    }

    virtual void summary()
    {
	BankAccount::summary();
	std::cout << this->owner << " is a VIP client!" << std::endl;
    }
protected:
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
    // Note that we can use a VIP account as a regular account!
    BankAccount* john_doe = new VIPAccount("John Doe");
    BankAccount* jane_doe = new BankAccount("Jane Doe");

    john_doe->withdraw(100); // John Doe is a VIP client, so he will go into negative balance
    jane_doe->withdraw(100); // Jane is a regular client, so she will stay at 0

    // We can even mix regular accounts and VIP accounts!
    std::vector<BankAccount*> bank;
    bank.push_back(john_doe);
    bank.push_back(jane_doe);

    printBank(bank);

    delete john_doe;
    delete jane_doe;
}
