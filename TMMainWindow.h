#ifndef TMMAINWINDOW_H
#define TMMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TMMainWindow; }
QT_END_NAMESPACE

class TMMainWindow : public QMainWindow {
Q_OBJECT

public:
    TMMainWindow(QWidget* parent = nullptr);
    ~TMMainWindow();
    void setViewModel(QObject* viewModel);

public slots:
    void populateToView();
    void populateToViewModel();

private:
    Ui::TMMainWindow *ui;
    QObject* viewModel;
};

#endif
