#include "TMMainWindow.h"
#include "TMMainWindowViewModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    auto view = QScopedPointer(new TMMainWindow());
    auto viewModel = QScopedPointer(new TMMainWindowViewModel());
    view->setViewModel(viewModel.get());
    view->show();

    return application.exec();
}
