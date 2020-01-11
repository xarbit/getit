#include "gui/HeaderWidget/HeaderControllerWidget.hpp"
#include "./ui_HeaderControllerWidget.h"

using namespace getit::gui;

HeaderControllerWidget::HeaderControllerWidget(QWidget* parent):
    QWidget(parent)
{
    ui->setupUi(this);
}

HeaderControllerWidget::~HeaderControllerWidget()
{
    delete ui;
}