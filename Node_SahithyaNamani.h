#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
class Node {
    
    friend class DoublyLinkedList;
    friend class SelectionSort;
    friend class BubbleSort;
    friend class InsertionSort;

public:
    Node(string name, int num);

    // set the number of stock  
    void setStockNum(int num);
    // get the number of stock 
    int getStockNum();
    // get the name of the stock
    string getStockName();
    // get the price of the stock
    double getPrice(); 
    // get the next of the node
    Node* getNext(); 

private:
    Node *prev;
    Node *next;

    string stockName;
    int stockNum;
    double price;
};

#endif 
