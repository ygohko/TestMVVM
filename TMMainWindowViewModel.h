#ifndef TMMAINWINDOWVIEWMODEL_H
#define TMMAINWINDOWVIEWMODEL_H

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
