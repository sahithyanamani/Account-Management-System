#ifndef SORTSTRATERGY_H
#define SORTSTRATERGY_H


/* 
Design Pattern - Stratergy Pattern
The Strategy Pattern is indeed a behavioral design pattern that allows defining a family of algorithms, 
encapsulating each one, and making them interchangeable. 
It enables the client to choose the algorithm at runtime without altering the object that uses it.
*/ 

// Forward declaration
class StockAccount;
class SortStratergy 
{
public:
    virtual void sortAccount(StockAccount& stockAccount) = 0;
    virtual ~SortStratergy() = default;
};

class Context 
{
public:
    Context(SortStratergy* sortstat);
    void sortUsingContext(StockAccount &stockAccount);
    ~Context();

private:
    SortStratergy* sortstat;
};

#endif 
