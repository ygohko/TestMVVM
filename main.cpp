#include "TMMainWindow.h"
#include "TMMainWindowViewModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TMMainWindow w;
    TMMainWindowViewModel viewModel;
    w.setViewModel(&viewModel);
    w.show();
    return a.exec();
}
