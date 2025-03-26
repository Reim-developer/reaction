#include <QtWidgets/QApplication>
#include "mainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MainWindow window;

    window.show();
    return application.exec();
}
