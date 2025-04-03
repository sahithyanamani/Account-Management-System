#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortStratergy_SahithyaNamani.h"
#include "StockAccount_SahithyaNamani.h"

// BubbleSort class inheriting from SortStrategy
class BubbleSort : public SortStratergy 
{
public:
// Override the sortAccount function
    void sortAccount(StockAccount& stockAccount) override;
};

#endif 