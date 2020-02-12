#pragma once

#include <QWidget>
#include <string>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class HeadersWidget; }
QT_END_NAMESPACE

namespace getit::gui::widget
{
    class HeadersWidget: public QWidget
    {
        Q_OBJECT

        public:
            HeadersWidget(QWidget* parent = nullptr);
            ~HeadersWidget();

            std::map<std::string, std::string> getHeaders();

        private:
            Ui::HeadersWidget* ui;
    };
}
