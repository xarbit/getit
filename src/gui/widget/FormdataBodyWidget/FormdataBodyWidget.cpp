#include "gui/widget/FormdataBodyWidget/FormdataBodyWidget.hpp"
#include "./ui_FormdataBodyWidget.h"

#include <iostream>

using namespace getit::gui::widget;

FormdataBodyWidget::FormdataBodyWidget(QWidget* parent):
    Body(parent),
    ui(new Ui::FormdataBodyWidget()),
    body(domain::FormdataRequestBody(FormdataBodyWidget::generateBoundary()))
{
    ui->setupUi(this);

    connect(ui->add, &QPushButton::pressed, this, [=]() {
        auto formdataWidget = new FormdataWidget();
        auto formdataListWidget = new QListWidgetItem(ui->formdataElements);
        auto size = formdataWidget->size();
        size.setWidth(formdataListWidget->sizeHint().width());

        formdataListWidget->setSizeHint(size);

        ui->formdataElements->setItemWidget(formdataListWidget, formdataWidget);
    });

    connect(ui->remove, &QPushButton::pressed, this, [=]() {
        auto selectedItems = ui->formdataElements->selectedItems();

        for (auto const selectedItem : selectedItems) {
            ui->formdataElements->removeItemWidget(selectedItem);

            delete selectedItem;
        }
    });
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
    for(int i = 0; i < ui->formdataElements->count(); ++i)
    {
        auto item = ui->formdataElements->item(i);
        auto widget = ui->formdataElements->itemWidget(item);

        if (auto formdata = dynamic_cast<FormdataWidget*>(widget)) {
            auto key = formdata->getKey();
            auto value = formdata->getValue();

            if (formdata->isFile()) {
                body.addFile(key, value);
            } else {
                body.addElement(key, value);
            }
        }
    }

    return &this->body;
}

std::string FormdataBodyWidget::generateBoundary()
{
    auto now = std::chrono::system_clock::now();
    auto milis = now.time_since_epoch().count();
    auto boundary = boost::format("%1%") % milis;

    return boundary.str();
}
