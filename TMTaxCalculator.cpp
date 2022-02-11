#include "TMTaxCalculator.h"

TMTaxCalculator::TMTaxCalculator(int price) {
    this->price = price;
    this->total = 0;
}

TMTaxCalculator::~TMTaxCalculator() {
    // Do nothing
}

void TMTaxCalculator::execute() {
    this->total = this->price + this->price / 10;
}

int TMTaxCalculator::getTotal() const {
    return this->total;
}
