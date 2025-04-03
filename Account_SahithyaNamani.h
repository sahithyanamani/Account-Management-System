#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Helper_SahithyaNamani.h"
using namespace std;

/*
Design Pattern - Template Method design pattern is a behavioral pattern that facilitates the creation
 of an algorithm's outline in a base class while enabling subclasses to redefine specific steps without
  altering the overall structure of the algorithm. This pattern promotes reusability and consistency across 
  similar algorithms.
*/

class Account 
{

public:

    Account();

    // setter for balance
    void setBalance(string balance);

    // getter for balance
    double getBalance() const;
    
    // print transaciton history
    virtual void displayTransactionHistory() const = 0;

    // Checks the shared and private file
    void fileStatusTemplate();
    
    // The `sharedFiles()` function, residing in the base class, serves to inspect the 
    //`cash_balance.txt` file, a task required by both the StockAccount and BankAccount subclasses.
    void sharedFiles();

    // The `privateFiles()` function, declared as virtual, will be individually implemented in the StockAccount 
    //and BankAccount classes to examine the specific files related to each of these account types.
    virtual void privateFiles();


    // Helper Function Object
    Helper helpfunc;
};

#endif 
