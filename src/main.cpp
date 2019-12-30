#include <QApplication>
#include "gui/MainWindow/MainWindow.hpp"

#include "domain/CppRestRequest.hpp"
#include "domain/RawRequestBody.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    Gui::MainWindow::MainWindow w;
    w.show();

    auto request = new getit::domain::CppRestRequest("GET", "https://google.com");
    auto body = new getit::domain::RawRequestBody();
    
    request->setBody(body);
    request->send([](getit::domain::Response response) {
        std::cout << response.body << std::endl;
    });

    return a.exec();
}