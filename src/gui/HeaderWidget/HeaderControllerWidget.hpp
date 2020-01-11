#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class HeaderControllerWidget; }
QT_END_NAMESPACE

namespace getit::gui
{
    class HeaderControllerWidget: public QWidget
    {
        Q_OBJECT

        public:
            HeaderControllerWidget(QWidget* parent = nullptr);
            ~HeaderControllerWidget();

        private:
            Ui::HeaderControllerWidget* ui;
    };
}