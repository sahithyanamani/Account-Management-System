#include "InsertionSort_SahithyaNamani.h"

void InsertionSort::sortAccount(StockAccount& stockAccount) 
{
    
    // Get a pointer to the first node after the head in the doubly linked list
    Node* tempPtr = stockAccount.doublyList.head->next;

    // Update prices in the nodes by finding the stock price using the stock name
    while (tempPtr != stockAccount.doublyList.tail) 
    {
        tempPtr->price = stockAccount.findStockPriceByName(tempPtr->getStockName()); 
        tempPtr = tempPtr->next;
    }
    
   // Get the size of the list
    int sz = stockAccount.doublyList.nodeNum;
     // Iterate through the list using the Insertion Sort algorithm
    for (int i = 1; i < sz; i++) 
    {
        Node* current = stockAccount.doublyList.findNodeByPosition(i);
        double currentValue = current->getStockNum() * current->price;
        int j = i - 1;
         // Perform the insertion sort algorithm to sort the nodes based on stock values
        while (j >= 0 && stockAccount.doublyList.findNodeByPosition(j)->getStockNum() * stockAccount.doublyList.findNodeByPosition(j)->price > currentValue) {
            
            Node* prev = stockAccount.doublyList.findNodeByPosition(j);
            stockAccount.doublyList.swapNode(j, j + 1);
            j--;
        }
    }
}

