#include "gui/widget/HeaderWidget/HeaderWidget.hpp"
#include "./ui_HeaderWidget.h"

using namespace getit::gui::widget;

HeaderWidget::HeaderWidget(QWidget* parent):
    QWidget(parent),
    ui(new Ui::HeaderWidget())
{
    ui->setupUi(this);
}

HeaderWidget::~HeaderWidget()
{
    delete ui;
}