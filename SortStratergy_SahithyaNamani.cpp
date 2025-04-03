#include "SortStratergy_SahithyaNamani.h"

// Constructor for Context class
Context::Context(SortStratergy* sortstat) {
	this->sortstat = sortstat;
}

// Method to sort using a specific strategy
void Context::sortUsingContext(StockAccount &stockAccount) {
    this->sortstat->sortAccount(stockAccount);
}

// Destructor for Context class
Context::~Context() {
    delete this->sortstat;
}