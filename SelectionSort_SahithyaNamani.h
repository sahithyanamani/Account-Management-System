#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SortStratergy_SahithyaNamani.h"
#include "StockAccount_SahithyaNamani.h"

class SelectionSort : public SortStratergy {
public:
    void sortAccount(StockAccount& stockAccount) override;
};

#endif 