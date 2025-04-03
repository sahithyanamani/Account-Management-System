#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "Account_SahithyaNamani.h"

// BankAccount class inheriting from Account

class BankAccount : public Account {
public:
    // Constructor for BankAccount
    BankAccount();

    // Display account details
    void displayAccountDetails() const;

     // Display transaction history
    void displayTransactionHistory() const;

    // Log current transaction into the file
    void logCurrentTransaction(int mode, double amount); 
    
    // Deposit money into the account
    void depositMoney(double mon);

    // Withdraw money from the account
    void withdrawMoney(double mon); 

protected:
    // Check its own files (virtual function)
    virtual void privateFiles(); 

};

#endif 
