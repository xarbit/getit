#include "gui/window/MainWindow/MainWindow.hpp"
#include "./ui_MainWindow.h"

using namespace getit::gui::window;

MainWindow::MainWindow(getit::domain::RequestFactory* requestFactory, QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow()),
    requestFactory(requestFactory),
    headerController(new widget::HeaderWidget(this)),
    bodyController(new widget::BodyWidget(this)),
    responseController(new widget::ResponseWidget(this))
{
    ui->setupUi(this);

    ui->headers->addWidget(headerController);
    ui->body->addWidget(bodyController);
    ui->response->addWidget(responseController);

    connect(ui->send, &QPushButton::clicked, this, [=]() {
        const std::string method = ui->method->currentText().toStdString();
        const std::string uri = ui->uri->text().toStdString();
        const auto headers = headerController->getHeaders();

        auto body = bodyController->getRequestBody();
        auto request = requestFactory->getRequest(method, uri);

        request->addHeaders(headers);
        request->setBody(body);
        request->send([=](getit::domain::Response response) {
            responseController->setResponse(response);
        });
    });
}

MainWindow::~MainWindow()
{
    delete headerController;
    delete bodyController;
    delete responseController;
    delete ui;
}
