#include "utils.hpp"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtGui/QScreen>

using namespace Reaction::Utils;

void Geometry::moveCenter(QWidget *window) {
    if(!window)
        return;

    QScreen *screen = QApplication::primaryScreen();
    if(!screen)
        return;

    QRect screenGeometry = screen->geometry();

    int x_point = (screenGeometry.width() - window->width() ) / 2;
    int y_point = (screenGeometry.height() - window->height()) / 2;

    window->move(x_point, y_point);
}
