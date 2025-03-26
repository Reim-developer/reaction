#ifndef mainWindow_HPP
#define mainWindow_HPP
#include <QtWidgets/QMainWindow>
#include "common/props.hpp"
#include "utils/utils.hpp"
#include "gui/include/label.hpp"

using namespace Reaction;
using namespace Reaction::Utils;


namespace Reaction {
    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *window = nullptr);
        ~MainWindow();

    private:
        AppProps *props;
        Geometry *geometry;
        Gui::GuiLabel *label;
    };
}
#endif // mainWindow_HPP
