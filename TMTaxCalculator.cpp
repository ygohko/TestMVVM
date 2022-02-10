#include "TMTaxCalculator.h"

TMTaxCalculator::TMTaxCalculator(int price) {
    this->price = price;
}

TMTaxCalculator::~TMTaxCalculator() {
    // Do nothing
}

int TMTaxCalculator::execute() {
    auto tax = this->price / 10;
    auto total = this->price + tax;

    return total;
}
