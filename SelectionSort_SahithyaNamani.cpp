#include "SelectionSort_SahithyaNamani.h"

// Sorting method using Selection Sort for StockAccount
void SelectionSort::sortAccount(StockAccount& stockAccount) {
    

	Node* tempPtr = stockAccount.doublyList.head->next;

    // Updating stock prices in the linked list
	while (tempPtr != stockAccount.doublyList.tail) {
		tempPtr->price = stockAccount.findStockPriceByName(tempPtr->getStockName()); 
		tempPtr = tempPtr->next;
	}
    int sz = stockAccount.doublyList.nodeNum;
	for (int i = 1; i <= sz - 1; i++) {
		int minm = i;
		for (int j = i+1 ; j <= sz; j++) {
			Node* stock_1 = stockAccount.doublyList.findNodeByPosition(minm);
			Node* stock_2 = stockAccount.doublyList.findNodeByPosition(j);

			double stock1 = (stock_1->getStockNum() * stock_1->price);
			double stock2 = (stock_2->getStockNum() * stock_2->price);
		// Compare the total value of stocks
			if (stock1 < stock2) {
				minm = j;
			}
		}
		        // Swap the nodes based on the calculated minimum

		stockAccount.doublyList.swapNode(i, minm);
	}
}