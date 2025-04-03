#include "DoublyLinkedList_SahithyaNamani.h"
#include<string>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    nodeNum = 0;
    // create empty head and empty tail
    // Create head node with empty values
    head = new Node("", 0);
    // Create tail node with empty values
    tail = new Node("", 0);
    // Set head's previous pointer to NULL
    head->prev = NULL;
    // Set head's next pointer to tail
    head->next = tail;
    // Set tail's previous pointer to head
    tail->prev = head;
    // Set tail's next pointer to NULL
    tail->next = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
    // Destructor to deallocate memory for nodes
    Node* currentPtr = head;
    while (currentPtr) {
        Node* tempPtr = currentPtr;
        currentPtr = currentPtr->next;
        // Delete current node
        delete tempPtr;
        tempPtr = NULL;
    }
}

// Getter methods
Node * DoublyLinkedList::getHead() const
{
    return head;
}

Node * DoublyLinkedList::getTail() const
{
    return tail;
}

int DoublyLinkedList::getSize() const
{
    return nodeNum;
}

// Insert a node into the doubly linked list
void DoublyLinkedList::insertNode(Node * node)
{
    //insert it before the tail and add the number of nodes
    node->next = tail;
    node->prev = tail->prev;
    tail->prev->next = node;
    tail->prev = node;
    nodeNum++;
}

// Delete a node with a specific stock name
void DoublyLinkedList::deleteNode(string stockName)
{
    // Find the node by stock name
    Node * node = findNode(stockName);
    // If the node is not found
    if (node == nullptr) 
    {
        cout << "Error: Stock not found." << endl;
    }
    // Delete the node
    else 
    { 
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete(node);
        nodeNum--;
    }
}

// Find a node by its stock name
Node * DoublyLinkedList::findNode(string stockName)
{
    Node * currentPtr = head->next;
    // Traverse the list to find the node with the given stock name
    while (currentPtr != tail) 
    { 
        if (currentPtr->stockName == stockName) 
        {
            return currentPtr;
        }
        currentPtr = currentPtr->next;
    }
    // Return null if the node is not found
    return nullptr;
}

// Find a node by its position in the list
Node * DoublyLinkedList::findNodeByPosition(int position) const
{
    // Check if the position is valid
    if (position > getSize()) 
    { 
        cout << "Error: invalid position." << endl;
        return nullptr;
    }
    else 
    {
        // Counter for the current position
        int cnt = 0; 
        Node* tempPtr = head->next;
        // Traverse to the specified position
        while ((cnt++) != position) 
        {
            tempPtr = tempPtr->next;
        }
        return tempPtr;
    }
}

void DoublyLinkedList::swapNode(int pos1, int pos2) 
{
    // Find node 1 and node 2 by their positions
    Node* n1 = findNodeByPosition(pos1); 
    Node* n2 = findNodeByPosition(pos2);
    // Both nodes must exist for swapping
    if (n1 == nullptr || n2 == nullptr) 
    {
        cout << "Error: invalid swap." << endl; 
        return;
    }
    if (n1->next == n2 ) 
    {
         // Nodes are adjacent
         // Call function to swap adjacent nodes
        swapAdjacentNodes(n1, n2);
    } 
    else 
    {
        // Nodes are not adjacent
        // Call function to swap non-adjacent nodes
        swapNonAdjacentNodes(n1, n2);
    }

}

// Swap two nodes in the list
void DoublyLinkedList::swapAdjacentNodes(Node* n1, Node* n2) 
{
    n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev->next = n2;
	n1->prev = n2;
	n2->next->prev = n1;
	n2->next = n1;
}

// Swap two non-adjacent nodes in the list
void DoublyLinkedList::swapNonAdjacentNodes(Node* n1, Node* n2) 
{
    Node* tempPtr = new Node("", 0);
	tempPtr->next = n1->next;
	tempPtr->prev = n1->prev;
	n1->prev->next = n2;
	n1->next->prev = n2;
	n1->prev = n2->prev;
	n1->next = n2->next;
	n2->prev->next = n1;
	n2->next->prev = n1;
	n2->prev = tempPtr->prev;
	n2->next = tempPtr->next;
    // Delete temporary pointer
	delete(tempPtr);
}

// Print function for debugging
void DoublyLinkedList::printList() 
{
    Node* currentPtr = head->next;
    while (currentPtr != tail) {
        cout << currentPtr->stockName << " ," << currentPtr->stockNum << endl;
        currentPtr = currentPtr->next;
    }
}
