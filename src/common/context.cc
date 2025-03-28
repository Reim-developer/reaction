#include "include/context.hpp"
#include "QtCore/qdir.h"
#include "QtCore/qfileinfo.h"
#include "QtWidgets/qcombobox.h"
#include "QtWidgets/qfiledialog.h"
#include "QtWidgets/qmainwindow.h"
#include "QtWidgets/qpushbutton.h"
#include "include/signal.hpp"
#include "include/state.hpp"
#include <QtWidgets/QFileDialog>

using namespace Reaction::Common;

void Context::setOpenFileContext(QPushButton *button, Signal *signal,
                                 QMainWindow *windows, QComboBox *comboBox, State *state) {
  QObject::connect(button, &QPushButton::clicked, signal, [=]() {
    QString filePath = QFileDialog::getOpenFileName(windows, "Choose boot file",
                                                    QDir::homePath(),
                                                    "Boot File (*.img *.iso)");

            if (!filePath.isEmpty()) {
                    QFileInfo fileInfo(filePath);
                    QString fileName = fileInfo.fileName();
                    comboBox->clear();
                    comboBox->addItem(fileName);
                    
                    state->isoFilePath = filePath;
            }
  });
}
