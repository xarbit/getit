#include "gui/ResponseControllerWidget/ResponseControllerWidget.hpp"
#include "./ui_ResponseControllerWidget.h"

using namespace getit::gui;

ResponseControllerWidget::ResponseControllerWidget(QWidget* parent):
    QWidget(parent),
    ui(new Ui::ResponseControllerWidget())
{
    ui->setupUi(this);
}

ResponseControllerWidget::~ResponseControllerWidget()
{
    delete ui;
}

void ResponseControllerWidget::setResponse(domain::Response response)
{

}