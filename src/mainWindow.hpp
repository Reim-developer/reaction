#ifndef mainWindow_HPP
#define mainWindow_HPP
#include <QtWidgets/QMainWindow>
#include "common/props.hpp"
#include "utils/utils.hpp"

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
    };
}
#endif // mainWindow_HPP
