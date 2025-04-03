#include "BankAccount_SahithyaNamani.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#include "Helper_SahithyaNamani.h"

// BankAccount constructor
// fileStatusTemplate() checks the status of files
BankAccount::BankAccount()
{
    // Calls a function to check file status upon object creation
    fileStatusTemplate();
}

void BankAccount::displayAccountDetails() const
{
    // Display the balance of the bank account
    cout << "You have $" << fixed << setprecision(2) << getBalance() << " in your bank account." << endl;
}

void BankAccount::displayTransactionHistory() const
{
    // Print all the content of BH_FILE
    helpfunc.printAllLines(BH_FILE); 
}

void BankAccount::logCurrentTransaction(int mode, double amount)
{
    string record = "";
    string type = "";
    // Determine the transaction type based on mode
    switch (mode) {
        case 1:
            type = "Deposit";
            break;
        case 2:
            type = "Withdraw";
            break;
        case 3:
            type = "SellStock";
            break;
        case 4:
            type = "BuyStock";
            break;
        default:
            break;
    }
    //store the type, amount, date and balance to a stringstream
    stringstream ss; 
    ss << left << "\n" << setw(16) << type << setw(16) << "$" + helpfunc.convertToStringDecimal(amount) << setw(16) <<
       helpfunc.getDate() << setw(16) << "$" + helpfunc.convertToStringDecimal(getBalance());
    //convert the stringstream to a string
    record = ss.str(); 
    //write to BH_FILE
    helpfunc.appendStringToLastLine(BH_FILE, record); 
}

void BankAccount::depositMoney(double mon)
{
    // Ensure the deposited amount is valid
    if (mon <= 0) 
    { 
        cout << "Error: invalid money." << endl;
        return;
    }
    else 
    {
        stringstream ss;
        ss << fixed << setprecision(2) << getBalance() + mon*1.0;
        //set balance and it will write it to file
        setBalance(ss.str());
        //add the history to file
        logCurrentTransaction(1, mon); 
        cout << "You have successfully deposit $" << fixed << setprecision(2) << mon << "." << endl;
        //print the details of bank account now to check
        displayAccountDetails(); 
    }
}

void BankAccount::withdrawMoney(double mon)
{
    double bal = getBalance();
    // Check if sufficient balance is available
    if (bal - mon < 0) 
    { 
        cout << "Error: insuficient fund." << endl;
    }
    else 
    {
        stringstream ss;
        ss << fixed << setprecision(2) << bal - mon*1.0;
        // Update balance
        setBalance(ss.str());
        // Add withdrawal history to the file 
        logCurrentTransaction(2, mon); 
        cout << "You have successfully withdraw $" << fixed << setprecision(2) << mon << "." << endl;
        // Display updated account details
        displayAccountDetails(); 
    }
}

void BankAccount::privateFiles()
{
    // If BANK_HISTORY_FILE does not exist
    if (!helpfunc.doesFileExist(BH_FILE))
    { 
        // Write the title of the file to the file
        stringstream ss; 
        ss << left << setw(16) << "Event" << setw(16) << "Amount" << setw(16) << "Date" << setw(16) << "Balance";
        string title = ss.str();
        helpfunc.appendStringToLastLine(BH_FILE, title);
    }
}