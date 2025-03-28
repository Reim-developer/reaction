#ifndef CONTEXT_HPP
#define CONTEXT_HPP
#include "QtWidgets/qcombobox.h"
#include "QtWidgets/qmainwindow.h"
#include "QtWidgets/qpushbutton.h"
#include "signal.hpp"

namespace Reaction::Common {
    class Context {
        public:
            void setOpenFileContext(QPushButton *button, Signal *signal, QMainWindow *windows, QComboBox *comboBox);
    };
}


#endif // CONTEXT_HPP
