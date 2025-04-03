#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "Helper_SahithyaNamani.h"
#include "BankAccount_SahithyaNamani.h"
#include "StockAccount_SahithyaNamani.h"
#include "DoublyLinkedList_SahithyaNamani.h"

// sort design pattern
void designPattern(); 
// Function to perform stock account operations
void accessStockAccount(); 
 // Function to perform bank account operations
void accessBankAccount();
// Function to store the portfolio value now to file
void exitMode(); 

// Template function to get positive numbers
template <class T>
T getPositive() {
    T m;
    while (true) {
        if (!(std::cin >> m) || m <= 0) 
        {
            // clear the error flag
            std::cin.clear(); 
            // discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "Error: Please enter a positive number!" << std::endl;
        } 
        else 
        {
            break;  // input is valid, exit the loop
        }
    }
    return m;
}

BankAccount bankAccount; //create an object of BankAccount
StockAccount stockAccount; //create an object of StockAccount

int main() {
    int choice = 0;
    while (choice != 4) 
    {
         //when user not chooses to quit
        cout << endl << "Welcome to the Account Management System." << endl;
        cout << "Please select an account to access:" << endl;
        cout << "1. Stock Portfolio Account" << endl;
        cout << "2. Bank Account" << endl;
        cout << "3. Select Sorting Design Pattern" << endl;
        cout << "4. Exit" << endl;
        cout << endl << "Option: ";
        cin >> choice; //get the choice

        switch (choice) //call different functions
        {
            case 1:
                accessStockAccount();
                break;
            case 2:
                accessBankAccount();
                break;
            case 3:
                designPattern();
                break;
            case 4:
                exitMode();
                break;
            default:
                cout << "Please enter the right choice!" << endl;
                break;
        }
    }
    return 0;
}

void designPattern()
{
	int choice = 0;
	while (choice != 4) 
    {
		cout << endl << "Design Pattern: Strategy" << endl;
		cout << "Please select an option :" << endl;
		cout << "1. Bubble Sort" << endl;
		cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
		cout << "4. Return to previous menu" << endl;
		cout << endl << "Option: ";
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			stockAccount.applySorting("BubbleSort");
			cout << "Sort Method is Bubble Sort" << endl;
			break;
		case 2:
			stockAccount.applySorting("SelectionSort");
			cout << "Sort Method is Selection Sort" << endl;
			break;
        case 3:
			stockAccount.applySorting("InsertionSort");
			cout << "Sort Method is Insertion Sort" << endl;
			break;
		case 4:
			break;
		default:
			cout << "Please enter the right choice!" << endl;
			break;
		}

        //update the strategy
		stockAccount.con_pattern = new Context(stockAccount.sort_stratergy); 

	}
}

void accessStockAccount()
{
    int choice = 0;
    while (choice != 7) 
    { //when user not chooses to quit
        cout << endl << "Stock Portfolio Account" << endl;
        cout << "Please select an option :" << endl;
        cout << "1. Display the price for a stock symbol" << endl;
        cout << "2. Display the current portfolio" << endl;
        cout << "3. Buy shares" << endl;
        cout << "4. Sell shares" << endl;
        cout << "5. View a graph for the portfolio value" << endl;
        cout << "6. View transaction history" << endl;
        cout << "7. Return to previous menu" << endl;
        cout << endl << "Option: ";
        cin >> choice;

        string name; //the name of the stock
        int num; //the number of the stock
        double price; //the price of the stock
        int designptr; //design pattern

        switch (choice)
        {
            case 1:
                cout << "Please enter the stock symbol: " << endl;
                cin >> name; //read in a line
                stockAccount.showStockInformation(name); //call this method to show the details of a stock
                break;
            case 2:
                stockAccount.applySorting("BubbleSort");
                stockAccount.displayAccountDetails(); //print the details of the current portfolio
                break;
            case 3:
                cout << "Please enter the stock symbol you wish to purchase: " << endl;
                cin >> name; //get the name
                cout << "Please enter the number of shares: " << endl;
                num = getPositive<int>(); //get the positive number
                cout << "Please enter the maximum amount you are willing to pay per share: " << endl << "$";
                price = getPositive<double>(); //get the positive amount
                stockAccount.purchaseStocks(name, num, price, bankAccount); //call the method to buy shares
                break;
            case 4:
                cout << "Please enter the stock symbol you wish to sell: " << endl;
                cin >> name; //get the name
                cout << "Please enter the number of shares: " << endl;
                num = getPositive<int>(); //get the positive number
                cout << "Please enter the minimum amount you are willing to sell per share: " << endl << "$";
                price = getPositive<double>(); //get the positive amount
                stockAccount.sellStocks(name, num, price, bankAccount); //call the method to sell shares
                break;
            case 5:
                stockAccount.plotGraphWithMatlab(); //print the graph by matlab
                break;
            case 6:
                stockAccount.displayTransactionHistory(); //print the transaction history
                break;
            case 7:
                break; //return to the previous menu
            default:
                cout << "Please enter the right choice!" << endl;
                break;
        }
    }
}

void accessBankAccount()
{
    int choice = 0;
    double money;
    while (choice != 5) 
    { //when user not to quit
        cout << endl << "Stock Portfolio Account" << endl;
        cout << "Please select an option :" << endl;
        cout << "1. View account balance" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Print out history" << endl;
        cout << "5. Return to previous menu" << endl;
        cout << endl << "Option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                bankAccount.displayAccountDetails(); //print the details of bank account
                break;
            case 2:
                cout << "Please enter the amount you wish to deposit:" << endl << "$";
                money = getPositive<double>(); //get positive value of money
                bankAccount.depositMoney(money); //call the mothod to deposit money
                stockAccount.setPortfolio(stockAccount.getPortfolio() + money); //add the money to portfolio value
                break;
            case 3:
                cout << "Please enter the amount you wish to withdraw:" << endl << "$";
                money = getPositive<double>(); //get positive value of money
                bankAccount.withdrawMoney(money); //call the mothod to withdraw money
                stockAccount.setPortfolio(stockAccount.getPortfolio() - money); //substract the money from portfolio value
                break;
            case 4:
                bankAccount.displayTransactionHistory(); //print the history of bank account
                break;
            case 5:
                break;
            default:
                cout << "Please enter the right choice!" << endl;
                break;
        }
    }
}

void exitMode()
{
    stockAccount.updatePortfolioValue(); //store the portfolio value now to file
}

