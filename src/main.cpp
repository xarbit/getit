#include <QApplication>
#include "gui/MainWindow/MainWindow.hpp"

#include <cpprest/http_client.h>
#include <iostream>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    Gui::MainWindow::MainWindow w;
    w.show();

    web::http::client::http_client c("https://wocoapp.nl/connect/api/v1/settings/fetch");

    web::http::http_request req;

    req.set_body("");
    req.set_method("GET");

    c.request(req).then([](web::http::http_response response) {
        std::cout << response.status_code() << std::endl;
        std::cout << response.extract_string().get() << std::endl;
    });

    return a.exec();
}