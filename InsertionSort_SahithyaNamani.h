#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "SortStratergy_SahithyaNamani.h"
#include "StockAccount_SahithyaNamani.h"

class InsertionSort : public SortStratergy {
public:
    void sortAccount(StockAccount& stockAccount) override;
};

#endif 