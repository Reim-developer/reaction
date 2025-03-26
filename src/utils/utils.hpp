#ifndef UTILS_HPP
#define UTILS_HPP
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtGui/QScreen>

namespace ReactionUtils {
    class Geometry {
        public:
            static void moveCenter(QWidget *window) {
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
    };
}

#endif // UTILS_HPP
