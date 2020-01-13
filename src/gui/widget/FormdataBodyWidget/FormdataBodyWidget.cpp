#include "gui/widget/FormdataBodyWidget/FormdataBodyWidget.hpp"
#include "./ui_FormdataBodyWidget.h"
#include <ctime>

using namespace getit::gui::widget;

FormdataBodyWidget::FormdataBodyWidget(QWidget* parent):
    Body(parent),
    ui(new Ui::FormdataBodyWidget()),
    body(domain::FormdataRequestBody(FormdataBodyWidget::generateBoundary()))
{
    ui->setupUi(this);
}

FormdataBodyWidget::~FormdataBodyWidget()
{
    delete ui;
}

std::string FormdataBodyWidget::getName()
{
    return this->name;
}

getit::domain::RequestBody* FormdataBodyWidget::getRequestBody()
{
    return &this->body;
}

std::string FormdataBodyWidget::generateBoundary()
{
    std::time_t time = std::time(nullptr);

    return "-----" + std::string(std::asctime(std::localtime(&time)));
}
