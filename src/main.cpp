#include <QApplication>
#include "gui/MainWindow/MainWindow.hpp"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    Gui::MainWindow::MainWindow w;
    w.show();

    return a.exec();
}