#include <QApplication>
#include "gui/window/MainWindow/MainWindow.hpp"

#include "domain/CppRestRequest.hpp"
#include "domain/RawRequestBody.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    getit::gui::window::MainWindow w;
    w.show();

    auto request = new getit::domain::CppRestRequest("GET", "https://google.com");
    auto body = new getit::domain::RawRequestBody();
    
    // request->setBody(body);
    request->send([](getit::domain::Response response) {
        std::cout << response.body << std::endl << response.statusCode << std::endl;
    });

    return a.exec();
}