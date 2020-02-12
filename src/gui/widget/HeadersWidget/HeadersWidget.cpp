#include "gui/widget/HeadersWidget/HeadersWidget.hpp"
#include "./ui_HeadersWidget.h"

using namespace getit::gui::widget;

HeadersWidget::HeadersWidget(QWidget* parent):
    QWidget(parent),
    ui(new Ui::HeadersWidget())
{
    ui->setupUi(this);
}

HeadersWidget::~HeadersWidget()
{
    delete ui;
}

std::map<std::string, std::string> HeadersWidget::getHeaders()
{
    std::map<std::string, std::string> map;

    return map;
}
