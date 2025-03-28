#ifndef mainWindow_HPP
#define mainWindow_HPP
#include <QtWidgets/QMainWindow>
#include "common/include/context.hpp"
#include "common/include/props.hpp"
#include "utils/utils.hpp"
#include "gui/include/label.hpp"
#include "gui/include/dropbox.hpp"
#include "gui/include/buttons.hpp"
#include "common/include/signal.hpp"

using namespace Reaction;
using namespace Reaction::Utils;
using namespace Reaction::Common;

namespace Reaction {
    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *window = nullptr);
        ~MainWindow();

    private:
        AppProps *props;
        Geometry *geometry;

        Signal *signal;
        Context *context;

        Gui::GuiLabel *guiLabel;
        Gui::GuiLabelUtils *guiLabelUtils;
        Gui::GuiDropbox *guiDropbox;
        Gui::GuiButtons *guiButtons;

    };
}
#endif // mainWindow_HPP
