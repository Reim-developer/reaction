#ifndef mainWindow_HPP
#define mainWindow_HPP
#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *window = nullptr);
    ~MainWindow();
};
#endif // mainWindow_HPP
