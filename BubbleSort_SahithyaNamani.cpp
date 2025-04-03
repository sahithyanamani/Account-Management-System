#include "BubbleSort_SahithyaNamani.h"

// Function to sort the StockAccount using Bubble Sort
void BubbleSort::sortAccount(StockAccount& stockAccount) {
    
	// Access the doubly linked list from the StockAccount
	Node* tempPtr = stockAccount.doublyList.head->next;

    // Update the price of every stock in the list
	while (tempPtr != stockAccount.doublyList.tail) 
	{
		tempPtr->price = stockAccount.findStockPriceByName(tempPtr->getStockName());
		tempPtr = tempPtr->next;
	}
    // Get the size of the list
    int sz = stockAccount.doublyList.nodeNum;
	// Bubble sort implementation
	for (int i = 1; i <= sz; i++) 
	{
		for (int j = i; j <= sz; j++) 
		{
			// Get the ith node
			Node* stock_1 = stockAccount.doublyList.findNodeByPosition(i);
			// Get the jth node
			Node* stock_2 = stockAccount.doublyList.findNodeByPosition(j);

			// Check if the nodes are not null
			if (stock_1 && stock_2) 
			{ 
				// Calculate the value of stocks by multiplying quantity with price
                double stock1 = stock_1->getStockNum() * stock_1->price;
                double stock2 = stock_2->getStockNum() * stock_2->price;

				// Swap the nodes if the value of stock_1 is less than stock_2
                if (stock1 < stock2) 
				{
					// Swap nodes in the list
                    stockAccount.doublyList.swapNode(i, j);
                }
            }
		}
	}
}