#ifndef UTILS_HPP
#define UTILS_HPP
#include "QtCore/qobject.h"
#include "QtWidgets/qwidget.h"
#include <QtWidgets/QWidget>

namespace Reaction::Utils {
    class Utils {
        public:
            void moveCenter(QWidget *window);
            QString showOpenDiskDialog(QWidget *window);
    };
}

#endif // UTILS_HPP
