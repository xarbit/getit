#pragma once

#include <QWidget>

#include "domain/Response.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class ResponseWidget; }
QT_END_NAMESPACE

namespace getit::gui::widget
{
    class ResponseWidget: public QWidget
    {
        Q_OBJECT

        public:
            ResponseWidget(QWidget* parent = nullptr);
            ~ResponseWidget();

            void setResponse(domain::Response response);

        private:
            Ui::ResponseWidget* ui;
    };
}