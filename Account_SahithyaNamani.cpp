#include "Account_SahithyaNamani.h"


void Account::setBalance(string balance)
{
    // writing balance to file
    helpfunc.writeStringToFile(CB_FILE, balance); 
}

Account::Account()
{
    // Checking the file status
    fileStatusTemplate(); 
}

double Account::getBalance() const
{
    // Code to get th elast line from the file
    string newest = helpfunc.getLastLineOfFile(CB_FILE);
     
    // Converting the last line to string format
    double balance_from_file = atof(newest.c_str()) * 1.0; 
    return balance_from_file;
}

void Account::fileStatusTemplate()
{
    //checking shared file
    sharedFiles();
     
    //Checking the private file
    privateFiles(); 
}

void Account::sharedFiles()
{
    //if CB_FILE not exist, initialize it to "10000"
    if (!helpfunc.doesFileExist(CB_FILE)) 
    { 
        string m = "10000.00";
        helpfunc.appendStringToLastLine(CB_FILE, m);
    }
}

void Account::privateFiles()
{
    //Does no functionality
}