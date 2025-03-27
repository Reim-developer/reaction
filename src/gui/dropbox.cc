#include "include/dropbox.hpp"

using namespace Reaction::Gui;

QComboBox *GuiDropbox::setComboBox(
    QWidget *widget, const QString &text,
    const int x_loc, const int y_loc,
    const int width, const int height) {

    QComboBox *comboBox = new QComboBox(widget);
    comboBox->addItem(text);
    comboBox->setGeometry(x_loc, y_loc, width, height);

    return comboBox;
}
