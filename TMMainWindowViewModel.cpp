#include "TMMainWindowViewModel.h"

#include "TMTaxCalculator.h"

TMMainWindowViewModel::TMMainWindowViewModel(QObject *parent) : QObject(parent) {
    /// @todo Implement this
}

void TMMainWindowViewModel::calculate() {
    /// @todo Implement this
    emit this->populateToViewModelRequested();
    auto calculator = QScopedPointer(new TMTaxCalculator(this->price));
    this->total = calculator->execute();
    emit this->populateToViewRequested();
}
