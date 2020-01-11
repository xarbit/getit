#include "gui/RequestBody/RawRequestBody/RawRequestBodyWidget.hpp"
#include "./ui_RawRequestBodyWidget.h"

using namespace getit::gui::requestbody;

RawRequestBodyWidget::RawRequestBodyWidget(QWidget* parent):
    BodyWidget(parent),
    ui(new Ui::RawRequestBodyWidget())
{
    ui->setupUi(this);
}

RawRequestBodyWidget::~RawRequestBodyWidget()
{
    delete ui;
}

std::string RawRequestBodyWidget::getName()
{
    return this->name;
}

getit::domain::RequestBody* RawRequestBodyWidget::getRequestBody()
{
    std::string contentType = ui->contentType->text().toStdString();
    std::string body = ui->rawBody->toPlainText().toStdString();

    this->body.setContentType(contentType);
    this->body.setBody(body);

    return &this->body;
}
