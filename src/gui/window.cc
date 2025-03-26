#include "../main.hpp"
#include "../common/props.hpp"
#include <QtWidgets/QWidget>
#include <QtCore/QString>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtGui/QScreen>

MainWindow::MainWindow(QWidget *window) : QMainWindow(window) {
    AppProps *props = new AppProps();
    props->application_name = "reaction!";
    props->application_version = "1.0.0";

    QString title_fmt = QString().asprintf("%s %s", 
        props->application_name, 
        props->application_version);

    setWindowTitle(title_fmt);
    resize(800, 600);

    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
}
