#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <string>
#include "Node_SahithyaNamani.h"

using namespace std;

class StockAccount;
class DoublyLinkedList
{
    // Friend classes for specialized sorting algorithms
    friend class BubbleSort;
    friend class SelectionSort;
    friend class InsertionSort;
public:
    // Constructor and Destructor
    DoublyLinkedList(); 
    ~DoublyLinkedList();
    // Getter functions
    Node* getHead() const; 
    Node* getTail() const;
    // Function to get the size of the list (excluding head and tail)
    int getSize() const; 
    // Functions to manipulate the list
    // Insert a node before the tail
    void insertNode(Node *node); 
    // Delete a node with a certain name
    void deleteNode(string stockName); 
     // Find a node with a certain name
    Node* findNode(string stockName); 

    // Functions to find and manipulate nodes by position
    // Find the node at a position (excluding head and tail)
    Node* findNodeByPosition(int position) const; 
    // Swap nodes at given positions
    void swapNode(int pos1, int pos2);
    // Swap adjacent nodes
    void swapAdjacentNodes(Node *n1, Node *n2);
     // Swap non-adjacent nodes
    void swapNonAdjacentNodes(Node *n1, Node *n2);

    // Print the content of the list for debugging
    void printList(); 

private:
// Head of the doubly linked list
    Node* head; 
    // Tail of the doubly linked list
    Node* tail; 
    // Number of nodes in the list (excluding head and tail)
    int nodeNum; 
};

#endif 
