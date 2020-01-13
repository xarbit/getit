#pragma once

#include <QWidget>
#include <string>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class HeaderWidget; }
QT_END_NAMESPACE

namespace getit::gui::widget
{
    class HeaderWidget: public QWidget
    {
        Q_OBJECT

        public:
            HeaderWidget(QWidget* parent = nullptr);
            ~HeaderWidget();

            std::map<std::string, std::string> getHeaders();

        private:
            Ui::HeaderWidget* ui;
    };
}
