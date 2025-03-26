#include "include/label.hpp"

using namespace Reaction::Gui;

QLabel *GuiLabel::setLabel(QWidget *widget, const QString &text,  const int x_loc, const int y_loc, 
    const int width, const int height) {

        QLabel *label = new QLabel(text, widget);
        label->setGeometry(x_loc, y_loc, width, height);

        return label;
}
