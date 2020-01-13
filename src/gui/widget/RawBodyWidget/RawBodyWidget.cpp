#include "gui/widget/RawBodyWidget/RawBodyWidget.hpp"
#include "./ui_RawBodyWidget.h"

using namespace getit::gui::widget;

RawBodyWidget::RawBodyWidget(QWidget* parent):
    Body(parent),
    ui(new Ui::RawBodyWidget())
{
    ui->setupUi(this);
}

RawBodyWidget::~RawBodyWidget()
{
    delete ui;
}

std::string RawBodyWidget::getName()
{
    return this->name;
}

getit::domain::RequestBody* RawBodyWidget::getRequestBody()
{
    std::string contentType = ui->contentType->text().toStdString();
    std::string body = ui->rawBody->toPlainText().toStdString();

    this->body.setContentType(contentType);
    this->body.setBody(body);

    return &this->body;
}
