#include "gui/widget/ResponseWidget/ResponseWidget.hpp"
#include "./ui_ResponseWidget.h"

using namespace getit::gui::widget;

ResponseWidget::ResponseWidget(QWidget* parent):
    QWidget(parent),
    ui(new Ui::ResponseWidget())
{
    ui->setupUi(this);
}

ResponseWidget::~ResponseWidget()
{
    delete ui;
}

void ResponseWidget::setResponse(getit::domain::Response response)
{

}