#ifndef TEST_HPP
#define TEST_HPP
#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *window = nullptr);
};
#endif // TEST_HPP
