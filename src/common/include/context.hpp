#ifndef CONTEXT_HPP
#define CONTEXT_HPP
#include "QtWidgets/qcombobox.h"
#include "QtWidgets/qmainwindow.h"
#include "QtWidgets/qpushbutton.h"
#include "signal.hpp"
#include "state.hpp"

namespace Reaction::Common {
class Context {
public:
  void setOpenFileContext(QPushButton *button, Signal *signal,
                          QMainWindow *windows, QComboBox *comboBox,
                          State *state);
  void setOpenDeviceContext(QPushButton *button, Signal *signal,
                            QMainWindow *windows, QComboBox *comboBox,
                            State *state);
  void setReloadDiskContext(QPushButton *button, Signal *signal,
                            QComboBox *comboBox, State *state);
};
} // namespace Reaction::Common

#endif // CONTEXT_HPP
