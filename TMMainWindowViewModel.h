#ifndef TMMAINWINDOWVIEWMODEL_H
#define TMMAINWINDOWVIEWMODEL_H

#include <QObject>

class TMMainWindowViewModel : public QObject {
    Q_OBJECT

public:
    explicit TMMainWindowViewModel(QObject* parent = nullptr);

    Q_PROPERTY(int price MEMBER price);
    Q_PROPERTY(int total MEMBER total);

    int price;
    int total;

signals:
    void populateToViewRequested();
    void populateToViewModelRequested();

public slots:
    void calculate();
};

#endif
