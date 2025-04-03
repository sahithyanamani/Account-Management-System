#include "Node_SahithyaNamani.h"

// Constructor for Node class
Node::Node(string name, int num)
        :stockName(name), stockNum(num), price(0.0)
{
    this->prev = NULL;
    this->next = NULL;
}

// Getter method for retrieving the next Node
Node * Node::getNext()
{
    return next;
}

// Getter method for retrieving the price
double Node::getPrice()
{
    return price;
}

// Setter method for setting the stock number
void Node::setStockNum(int num)
{
    stockNum = num;
}

// Getter method for retrieving the stock number
int Node::getStockNum()
{
    return stockNum;
}

// Getter method for retrieving the stock name
string Node::getStockName()
{
    return stockName;
}

