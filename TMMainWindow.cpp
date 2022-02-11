#include "TMMainWindow.h"
#include "ui_TMMainWindow.h"

TMMainWindow::TMMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::TMMainWindow) {
    ui->setupUi(this);
}

TMMainWindow::~TMMainWindow() {
    delete ui;
}

void TMMainWindow::setViewModel(QObject* viewModel) {
    this->viewModel = viewModel;
    this->connect(ui->calculateButton, SIGNAL(clicked()), viewModel, SLOT(calculate()));
    this->connect(viewModel, SIGNAL(populationToViewRequested(int)), this, SLOT(populateToView(int)));
    this->connect(viewModel, SIGNAL(populationToViewModelRequested(int)), this, SLOT(populateToViewModel(int)));
}

void TMMainWindow::populateToView(int hint) {
    Q_UNUSED(hint);
    ui->totalLineEdit->setText(QString("%1").arg(this->viewModel->property("total").toInt()));
}

void TMMainWindow::populateToViewModel(int hint) {
    Q_UNUSED(hint);
    this->viewModel->setProperty("price", ui->priceLineEdit->text().toInt());
}
