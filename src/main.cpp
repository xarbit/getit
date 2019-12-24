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

    // web::http::client::http_client c("https://wocoapp.nl/connect/api/v1/settings/fetch");

    // web::http::http_request req;

    // req.set_body("");
    // req.set_method("GET");

    // c.request(req).then([](web::http::http_response response) {
    //     std::cout << response.status_code() << std::endl;
    //     std::cout << response.extract_string().get() << std::endl;
    // });

    auto request = new getit::domain::CppRestRequest("GET", "https://google.com");
    auto body = new getit::domain::RawRequestBody();
    
    request->setBody(body);
    request->send([](getit::domain::Response response) {
        std::cout << response.body << std::endl;
    });

    return a.exec();
}