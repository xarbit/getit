#include "gui/RequestBody/FormdataRequestBody/FormdataRequestBodyWidget.hpp"
#include "./ui_FormdataRequestBodyWidget.h"
#include <ctime>

using namespace getit::gui::requestbody;

FormdataRequestBodyWidget::FormdataRequestBodyWidget(QWidget* parent):
    BodyWidget(parent),
    ui(new Ui::FormdataRequestBodyWidget()),
    body(getit::domain::FormdataRequestBody(FormdataRequestBodyWidget::generateBoundary()))
{
    ui->setupUi(this);
}

FormdataRequestBodyWidget::~FormdataRequestBodyWidget()
{
    delete ui;
}

std::string FormdataRequestBodyWidget::getName()
{
    return this->name;
}

getit::domain::RequestBody* FormdataRequestBodyWidget::getRequestBody()
{
    return &this->body;
}

std::string FormdataRequestBodyWidget::generateBoundary()
{
    std::time_t time = std::time(nullptr);

    return "-----" + std::string(std::asctime(std::localtime(&time)));
}
