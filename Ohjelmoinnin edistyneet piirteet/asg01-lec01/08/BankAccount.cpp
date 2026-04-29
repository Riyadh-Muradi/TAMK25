#include "BankAccount.h"
#include <stdexcept>
#include <string>
using namespace std;

BankAccount::BankAccount() : owner(""), id(0), balance(0.0) {}
BankAccount::BankAccount(string owner, int id, double balance) : owner(owner), id(id), balance(balance)
{
    if (id < 0 || balance < 0.0)
        throw runtime_error("Invalid initial state");
}
string BankAccount::getOwner() const { return owner; }
int BankAccount::getId() const { return id; }
double BankAccount::getBalance() const { return balance; }
void BankAccount::setOwner(string o) { owner = o; }
void BankAccount::setId(int i)
{
    if (i < 0)
        throw runtime_error("Bad ID");
    id = i;
}
void BankAccount::setBalance(double b)
{
    if (b < 0.0)
        throw runtime_error("Bad Balance");
    balance = b;
}
bool BankAccount::deposit(double amount)
{
    if (amount <= 0)
        return false;
    balance += amount;
    return true;
}
bool BankAccount::withdraw(double amount)
{
    if (amount <= 0 || balance < amount)
        return false;
    balance -= amount;
    return true;
}
string BankAccount::toString() const
{
    return "BankAccount(\"" + owner + "\", " + to_string(id) + ", " + to_string(balance) + ")";
}
bool BankAccount::operator==(const BankAccount &other) const { return id == other.id; }
BankAccount BankAccount::operator+(const BankAccount &other) const
{
    return BankAccount("combined", 0, balance + other.balance);
}
ostream &operator<<(ostream &os, const BankAccount &ba)
{
    os << ba.toString();
    return os;
}