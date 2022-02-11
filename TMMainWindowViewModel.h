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

#ifndef TMMAINWINDOWVIEWMODEL_H
#define TMMAINWINDOWVIEWMODEL_H

// Qt includes
#include <QObject>

class TMMainWindowViewModel : public QObject {
    Q_OBJECT

public:
    explicit TMMainWindowViewModel(QObject* parent = nullptr);

    Q_PROPERTY(int price MEMBER price);
    Q_PROPERTY(int total MEMBER total);

signals:
    void populationToViewRequested(int hint);
    void populationToViewModelRequested(int hint);

public slots:
    void calculate();

private:
    int price;
    int total;
};

#endif
