#include "Helper_SahithyaNamani.h"
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<time.h>
#include<iomanip>
using namespace std;

// Constructor for the Helper class
Helper::Helper() { }

// Method to convert a double to a string with two decimal points
string Helper::convertToStringDecimal(double d) const
{
    // Read in the double to stringstream and convert it to string with two decimal points
    stringstream ss;
    // Set two decimal points 
    ss << fixed << setprecision(2) << d; 
    return ss.str();
}

// Method to convert a double to a string
string Helper::convertToString(double d) const
{
    stringstream ss;
    ss << d;
    return ss.str();
}

// Method to convert time to a string
string Helper::convertTimeToString(long d) const
{
    stringstream ss;
    ss << d;
    return ss.str();
}


string Helper::getDate() const
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    //format the date
    string time = convertToString(1 + ltm->tm_mon) + "/" +
                  convertToString(ltm->tm_mday) + "/" + convertToString(1900 + ltm->tm_year);
    return time;
}

// Method to get the current date in string format
string Helper::getTime() const
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    //format the time
    string time = convertToString(ltm->tm_hour) + ":" +
                  convertToString(ltm->tm_min) + ":" + convertToString(ltm->tm_sec);
    return time;
}

// Method to get time in seconds
time_t Helper::getTimeInSeconds() const
{
    time_t seconds = time(0);
    return seconds;
}

// Method to check if a file exists
bool Helper::doesFileExist(string file_name) const
{
    fstream fs;
    bool result;
    fs.open(file_name, ios::in | ios::out); //it will build the file automatically if file does not exist
    int ch;
    ch = fs.get(); //try to read a char in file
    if (ch == EOF) { //if read a EOF, it means nothing in file
        result = false;
    }
    else {
        result = true;
    }
    fs.close();
    return result;
}

// Method to clear contents of a file
void Helper::clearFile(string file_name)
{
    ofstream ofs;
    ofs.open(file_name);
    if (ofs.fail()) { //faile to open file
        cout << "Error: " << file_name << " cannot open" << endl;
        return;
    }
    else {
        ofs << ""; //rewrite "" to the file
        ofs.close();
    }
}

// Method to search for a key in a file and return the line containing the key
string Helper::searchFileForKey(string file_name, string key) const
{
    string result = "";
    ifstream ifs;
    ifs.open(file_name);
    if (ifs.fail()) {
        cerr << "Error: " << strerror(errno);
        cout << "Error: " << file_name << " cannot open" << endl;
    }
    else {
        string line;
        while (getline(ifs, line)) {
            if (getNthWordFromString(line, 1) == key) {//get the first word in the line, compare it with the key
                result = line;
                break;
            }
        }
    }
    return result;
}

// Method to get the number of lines in a file
int Helper::getNumberOfLines(string file_name) const
{
    int num = 0;
    ifstream ifs;
    ifs.open(file_name);
    if (ifs.fail()) {
        cout << "Error: " << file_name << " cannot open" << endl;
        return 0;
    }
    else {
        string line;
        while (getline(ifs, line)) {
            num++;//just go over the file and add the num
        }
        ifs.close();
    }
    return num;
}

// Method to print all lines of a file
void Helper::printAllLines(string file_name) const
{
    ifstream ifs;
    ifs.open(file_name);
    if (ifs.fail()) {
        cout << "Error: " << file_name << " cannot open" << endl;
        return;
    }
    else {
        string line;
        while (getline(ifs, line)) {
            cout << line << endl; //print every line
        }
        ifs.close();
    }
}

// Method to write a string to a file, overwriting its content
void Helper::writeStringToFile(string file_name, string s)
{
    clearFile(file_name);
    fstream fs;
    fs.open(file_name);
    if (fs.fail()) {
        cout << "Error: " << file_name << " cannot open" << endl;
        return;
    }
    else {
        fs << s; //rewrite the number d to the file
        fs.close();
    }
}

// Method to append a string to the last line of a file
void Helper::appendStringToLastLine(string file_name, string str)
{
    ofstream ofs;
    ofs.open(file_name, ios::app);// use "ios::app" to move the pointer to the end of file
    if (ofs.fail()) {
        cout << "Error: " << file_name << " cannot open" << endl;
        return;
    } else {
        ofs << str; //write str to the last line
        ofs.close();
    }
}

// Method to get the last line of a file
string Helper::getLastLineOfFile(string file_name) const
{
    string lastline;
    ifstream ifs;
    ifs.open(file_name);
    if (ifs.fail()) {
        cout << "Error: " << file_name << " cannot open" << endl;
        return "";
    }
    else {
        while (getline(ifs, lastline)) {} //when while finishes, the lastline will be the content of last line
        ifs.close();
    }
    return lastline;
}

// Method to get the nth word from a string separated by '\t'
string Helper::getNthWordFromString(string str, int num) const
{
    stringstream strs(str);
    string tok;
    int cnt = 0;
    while (getline(strs, tok, '\t') && ((++cnt) != num)) {} //get the num-th word seperated by "\t" in the string
    return tok;
}