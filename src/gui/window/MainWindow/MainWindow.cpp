#include "gui/window/MainWindow/MainWindow.hpp"
#include "./ui_MainWindow.h"

using namespace getit::gui::window;

MainWindow::MainWindow(getit::domain::RequestFactory* requestFactory, QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow()),
    requestFactory(requestFactory),
    headersController(new widget::HeadersWidget(this)),
    bodyController(new widget::BodyWidget(this)),
    responseController(new widget::ResponseWidget(this))
{
    ui->setupUi(this);

    ui->headers->addWidget(headersController);
    ui->body->addWidget(bodyController);
    ui->response->addWidget(responseController);

    connect(ui->send, &QPushButton::clicked, this, [=]() {
        const std::string method = ui->method->currentText().toStdString();
        const std::string uri = ui->uri->text().toStdString();
        const auto headers = headersController->getHeaders();

        const auto body = bodyController->getRequestBody();
        const auto request = requestFactory->getRequest(method, uri);

        request->addHeaders(headers);
        request->setBody(body);
        request->send([=](getit::domain::Response* response) {
            emit requestSent(response);
        });
    });

    connect(this, &MainWindow::requestSent, responseController, &gui::widget::ResponseWidget::setResponse);
}

MainWindow::~MainWindow()
{
    delete headersController;
    delete bodyController;
    delete responseController;
    delete ui;
}
