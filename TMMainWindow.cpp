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
    this->connect(viewModel, SIGNAL(populateToViewRequested()), this, SLOT(populateToView()));
    this->connect(viewModel, SIGNAL(populateToViewModelRequested()), this, SLOT(populateToViewModel()));
}

void TMMainWindow::populateToView() {
    /// @todo Implement this
    ui->priceLineEdit->setText(QString("%1").arg(this->viewModel->property("price").toInt()));
    ui->totalLineEdit->setText(QString("%1").arg(this->viewModel->property("total").toInt()));
}

void TMMainWindow::populateToViewModel() {
    /// @todo Implement this
    this->viewModel->setProperty("price", ui->priceLineEdit->text().toInt());
    this->viewModel->setProperty("total", ui->totalLineEdit->text().toInt());
}
