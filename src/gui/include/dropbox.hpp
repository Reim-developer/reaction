#ifndef DROPBOX_HPP
#define DROPBOX_HPP
#include <QtWidgets/QComboBox>
#include <QtWidgets/QWidget>
#include <QtCore/QString>

namespace Reaction::Gui {
    class GuiDropbox {
        public:
        QComboBox *setComboBox(
            QWidget *widget, const QString &text,
            const int x_loc, const int y_loc,
            const int width, const int height
        );
    };
}

#endif // DROPBOX_HPP
