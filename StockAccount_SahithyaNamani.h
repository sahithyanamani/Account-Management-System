#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H
#include <iostream>
#include "Account_SahithyaNamani.h"
#include "BankAccount_SahithyaNamani.h"
#include "SortStratergy_SahithyaNamani.h"
#include "DoublyLinkedList_SahithyaNamani.h"

using namespace std;

class SortStratergy;
class Context;
class StockAccount : public Account 
{

    friend class BubbleSort;
    friend class SelectionSort;
    friend class InsertionSort;

public:
    StockAccount();
    ~StockAccount();

    void retrieveEveryStock(); 
    // sell stocks
    void sellStocks(string name, int num, double price, BankAccount &baAcc); 
    // buy stocks
    void purchaseStocks(string name, int num, double price, BankAccount &baAcc); 
    // find the price of a stock randomly from files by using its name
    double findStockPriceByName(string name) const; 
    // show the detail of a stock
    void showStockInformation(string name); 
    // write the new stock information to file
    void updateStockFile(); 
    // Portfilio value from file
    double getPortfolioFromFile() const; 
    // Set portfolio value
    void setPortfolio(double p);  
    double getPortfolio();
    void displayAccountDetails();
    void displayTransactionHistory() const;

    void applySorting(string type);  
    void setSortStratergy(SortStratergy* stratergy);

    // get all stock from file and store it to doubly linked list
    
    // write the new portfolio value along with the time to file
    void updatePortfolioValue(); 
    // add history to file
    void logCurrentTransaction(int mode, string name, int num, double pricepershare); 
    // MATLAB graph
    void plotGraphWithMatlab(); 

    SortStratergy* sort_stratergy;
    Context* con_pattern;

private:
    DoublyLinkedList doublyList;
    double portfolio;

protected:
    virtual void privateFiles(); //check its own files
};

#endif
