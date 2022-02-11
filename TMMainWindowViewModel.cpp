#include "TMMainWindowViewModel.h"

#include "TMTaxCalculator.h"

TMMainWindowViewModel::TMMainWindowViewModel(QObject *parent) : QObject(parent) {
    this->price = 0;
    this->total = 0;
}

void TMMainWindowViewModel::calculate() {
    emit this->populationToViewModelRequested(0);
    auto calculator = QScopedPointer(new TMTaxCalculator(this->price));
    calculator->execute();
    this->total = calculator->getTotal();
    emit this->populationToViewRequested(0);
}
