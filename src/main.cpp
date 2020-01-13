#include <QApplication>
#include "gui/window/MainWindow/MainWindow.hpp"

#include "domain/RequestFactory.hpp"

int main(int argc, char** argv)
{
    auto requestFactory = new getit::domain::RequestFactory("cpprestsdk");

    QApplication a(argc, argv);
    getit::gui::window::MainWindow w(requestFactory);
    w.show();

    return a.exec();
}
