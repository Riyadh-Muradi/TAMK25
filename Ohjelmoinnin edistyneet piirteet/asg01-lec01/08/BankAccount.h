#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <iostream>

class BankAccount
{
private:
    std::string owner;
    int id;
    double balance;

public:
    BankAccount();
    BankAccount(std::string owner, int id, double balance);
    std::string getOwner() const;
    int getId() const;
    double getBalance() const;
    void setOwner(std::string owner);
    void setId(int id);
    void setBalance(double balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    std::string toString() const;
    bool operator==(const BankAccount &other) const;
    BankAccount operator+(const BankAccount &other) const;
    friend std::ostream &operator<<(std::ostream &os, const BankAccount &ba);
};
#endif