#include "../mainWindow.hpp"
#include "../common/props.hpp"
#include "../utils/utils.hpp"
#include <QtWidgets/QWidget>
#include <QtCore/QString>
#include <QtWidgets/QMainWindow>

using namespace Reaction;
using namespace Reaction::Utils;


MainWindow::MainWindow(QWidget *window) : QMainWindow(window) {
    props = new AppProps();
    props->application_name = "reaction!";
    props->application_version = "1.0.0";

    QString title_fmt = QString().asprintf("%s %s", 
        props->application_name, 
        props->application_version);

    setWindowTitle(title_fmt);
    resize(800, 600);

    geometry = new Geometry();
    geometry->moveCenter(this);

    label = new Gui::GuiLabel();
    label->setLabel(this, "Drive Properties", 10, 1, 100, 30);
}

MainWindow::~MainWindow() {
    delete props;
    delete geometry;
    delete label;
}
