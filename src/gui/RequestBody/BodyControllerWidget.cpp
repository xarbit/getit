#include "gui/RequestBody/BodyControllerWidget.hpp"
#include "./ui_BodyControllerWidget.h"

using namespace getit::gui::requestbody;

BodyControllerWidget::BodyControllerWidget(QWidget* parent):
    QTabWidget(parent),
    ui(new Ui::BodyControllerWidget())
{
    ui->setupUi(this);

    for (auto const& body: this->bodies) {
        this->addTab(body, body->getName().c_str());
    }
}

BodyControllerWidget::~BodyControllerWidget()
{
    delete ui;
}
