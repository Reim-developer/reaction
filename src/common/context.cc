#include "QtWidgets/qpushbutton.h"
#include "include/signal.hpp"
#include "include/context.hpp"

using namespace Reaction::Common;

void Context::setOpenFileContext(QPushButton *button, Signal *signal) {
    QObject::connect(button, &QPushButton::clicked, signal, [=]() {
        signal->openFileDialog();
    });
}
