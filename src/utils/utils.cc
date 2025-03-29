#include "utils.hpp"
#include "QtCore/qcontainerfwd.h"
#include "QtCore/qdir.h"
#include "QtCore/qobject.h"
#include "QtGui/qwindowdefs.h"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qdialog.h"
#include <QtWidgets/QVBoxLayout>
#include "QtWidgets/qdialogbuttonbox.h"
#include "QtWidgets/qlistwidget.h"
#include "QtWidgets/qwidget.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtGui/QScreen>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtCore/QStorageInfo>

using namespace Reaction::Utils;

void Utils::moveCenter(QWidget *window) {
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

QString Utils::showOpenDiskDialog(QWidget *window) {
    QDialog dialog(window);
    dialog.setWindowTitle("Device Selection");
    dialog.setFixedSize(200, 300);

    QVBoxLayout boxLayout(&dialog);
    QListWidget listWidget(&dialog);
    QDialogButtonBox dialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);

    QDir dir("/sys/block");
    QStringList stringList = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(const QString &device : stringList ) {
       listWidget.addItem(device);
    }
    boxLayout.addWidget(&listWidget);
    boxLayout.addWidget(&dialogButtonBox);

    QObject::connect(&dialogButtonBox, &QDialogButtonBox::accepted, [&]() {
        if(listWidget.currentItem())
            dialog.accept();
    });

    QObject::connect(&dialogButtonBox, &QDialogButtonBox::rejected, [&]() {
        dialog.reject();
    });

    return (dialog.exec() == QDialog::Accepted && listWidget.currentItem() ? listWidget.currentItem()->text() : "");
}
