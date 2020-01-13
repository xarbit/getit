#include "gui/HeaderWidget/HeaderControllerWidget.hpp"
#include "./ui_HeaderControllerWidget.h"

using namespace getit::gui;

HeaderControllerWidget::HeaderControllerWidget(QWidget* parent):
    QWidget(parent),
    ui(new Ui::HeaderControllerWidget())
{
    ui->setupUi(this);
}

HeaderControllerWidget::~HeaderControllerWidget()
{
    delete ui;
}