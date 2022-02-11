/*
 * Copyright (c) 2021 Yasuaki Gohko
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE ABOVE LISTED COPYRIGHT HOLDER(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

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
