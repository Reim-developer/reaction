#include "../mainWindow.hpp"
#include "../common/include/props.hpp"
#include "../common/include/signal.hpp"
#include "../utils/utils.hpp"
#include "QtCore/qobject.h"
#include "QtWidgets/qcombobox.h"
#include "QtWidgets/qpushbutton.h"
#include "include/buttons.hpp"
#include "include/dropbox.hpp"
#include <QtWidgets/QWidget>
#include <QtCore/QString>
#include <vector>
#include <QtWidgets/QMainWindow>

using namespace std;
using namespace Reaction;
using namespace Reaction::Utils;
using namespace Reaction::Common;

MainWindow::MainWindow(QWidget *window) : QMainWindow(window) {
    props = new AppProps();
    props->application_name = "reaction!";
    props->application_version = "1.0.0";

    QString title_fmt = QString().asprintf("%s %s", 
        props->application_name, 
        props->application_version);

    setWindowTitle(title_fmt);
    setFixedSize(800, 600);

    geometry = new Geometry();
    geometry->moveCenter(this);

    guiLabel = new Gui::GuiLabel();
    QLabel *deviceSelect = guiLabel->setLabel(this, "Device Selection:", 10, 30, 100, 30);
    QLabel *bootFileSelect = guiLabel->setLabel(this, "Boot File Selection:", 10, 100, 100, 30);
    QLabel *partitionSelect = guiLabel->setLabel(this, "Partition Selection", 10, 170, 100, 30);

    guiLabelUtils = new Gui::GuiLabelUtils();
    guiLabelUtils->setLabelFixedSize(deviceSelect, 12);
    guiLabelUtils->setLabelFixedSize(bootFileSelect, 12);
    guiLabelUtils->setLabelFixedSize(partitionSelect, 12);

    guiDropbox = new Gui::GuiDropbox();
    QComboBox *deviceList = guiDropbox->setComboBox(this, "No device found", 10, 60, 150, 30);
    static_cast<Gui::GuiDropboxStyle*>(deviceList)->setTransparent(true);

    QComboBox *bootSelctionList = guiDropbox->setComboBox(this, "No boot file", 10, 130, 150, 30);
    static_cast<Gui::GuiDropboxStyle*>(bootSelctionList)->setTransparent(true);

    vector<QString> partitionSelectionList = {"MBR", "GPT"};
    QComboBox *selectPartition = guiDropbox->setMultiComboBox(this, partitionSelectionList, 10, 200,  150, 30);
    static_cast<Gui::GuiDropboxStyle*>(selectPartition)->setTransparent(true);

    guiButtons = new Gui::GuiButtons();

    guiButtons->setButtons(this, "Device not found? Reload", 300, 60, 200, 30);
    guiButtons->setButtons(this, "Choose device manually",530, 60, 200, 30);

    QPushButton *openBootFileButton  = guiButtons->setButtons(this, "Choose boot file", 300, 130, 200, 30);
    
    signal = new Signal(this);
    context = new Context();
    context->setOpenFileContext(openBootFileButton, signal, this, bootSelctionList);
}

MainWindow::~MainWindow() {
    delete props;
    delete geometry;
    delete guiLabel;
    delete guiLabelUtils;
    delete guiDropbox;
    delete guiButtons;
    delete signal;
    delete context;
}
