#include "gui/widget/BodyWidget/BodyWidget.hpp"
#include "./ui_BodyWidget.h"

using namespace getit::gui::widget;

BodyWidget::BodyWidget(QWidget* parent):
    QTabWidget(parent),
    ui(new Ui::BodyWidget())
{
    ui->setupUi(this);

    for (auto const& body: this->bodies) {
        this->addTab(body, body->getName().c_str());
    }
}

BodyWidget::~BodyWidget()
{
    delete ui;
}

getit::domain::RequestBody* BodyWidget::getRequestBody()
{
    return bodies.at(currentIndex())->getRequestBody();
}
