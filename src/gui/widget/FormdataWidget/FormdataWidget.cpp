#include "gui/widget/FormdataWidget/FormdataWidget.hpp"
#include "./ui_FormdataWidget.h"

using namespace getit::gui::widget;

FormdataWidget::FormdataWidget(QWidget* parent):
    QWidget(parent),
    ui(new Ui::FormdataWidget())
{
    ui->setupUi(this);

    connect(ui->type, qOverload<int>(&QComboBox::currentIndexChanged), this, [=](int index) {
        ui->file->setHidden(index == textTypeIndex);
        ui->browse->setHidden(index == textTypeIndex);

        ui->value->setHidden(index == fileTypeIndex);
    });

    connect(ui->browse, &QPushButton::pressed, this, [=]() {
        auto fileName = QFileDialog::getOpenFileUrl(this);

        if (!fileName.isEmpty()) {
            ui->file->setText(fileName.toString());
        }
    });

    ui->type->setCurrentIndex(textTypeIndex);
}

FormdataWidget::~FormdataWidget()
{
    delete ui;
}

bool FormdataWidget::isFile()
{
    return ui->type->currentIndex() == fileTypeIndex;
}

std::string FormdataWidget::getKey()
{
    return ui->key->text().toStdString();
}

std::string FormdataWidget::getValue()
{
    if (isFile()) {
        return ui->file->text().toStdString();
    }

    return ui->value->text().toStdString();
}
