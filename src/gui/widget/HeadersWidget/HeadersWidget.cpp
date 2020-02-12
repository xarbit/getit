#include "gui/widget/HeadersWidget/HeadersWidget.hpp"
#include "./ui_HeadersWidget.h"

using namespace getit::gui::widget;

HeadersWidget::HeadersWidget(QWidget* parent):
    QWidget(parent),
    ui(new Ui::HeadersWidget())
{
    ui->setupUi(this);

    connect(ui->add, &QPushButton::pressed, this, [=]() {
        auto headerWidget = new HeaderWidget();
        auto headerListWidget = new QListWidgetItem(ui->headers);
        auto size = headerWidget->size();
        size.setWidth(headerListWidget->sizeHint().width());

        headerListWidget->setSizeHint(size);

        ui->headers->setItemWidget(headerListWidget, headerWidget);
    });

    connect(ui->remove, &QPushButton::pressed, this, [=]() {
        auto selectedItems = ui->headers->selectedItems();

        for (auto const selectedItem: selectedItems) {
            ui->headers->removeItemWidget(selectedItem);
            delete selectedItem;
        }
    });
}

HeadersWidget::~HeadersWidget()
{
    delete ui;
}

std::map<std::string, std::string> HeadersWidget::getHeaders()
{
    std::map<std::string, std::string> map;

    for (int i = 0; i < ui->headers->count(); ++i) {
        auto item = ui->headers->item(i);
        auto widget = ui->headers->itemWidget(item);

        if (auto header = dynamic_cast<HeaderWidget*>(widget)) {
            auto key = header->getKey();
            auto value = header->getValue();

            map.insert({key, value});
        }
    }

    return map;
}
