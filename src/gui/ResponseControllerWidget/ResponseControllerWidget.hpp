#pragma once

#include <QWidget>

#include "domain/Response.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class ResponseControllerWidget; }
QT_END_NAMESPACE

namespace getit::gui
{
    class ResponseControllerWidget: public QWidget
    {
        Q_OBJECT

        public:
            ResponseControllerWidget(QWidget* parent = nullptr);
            ~ResponseControllerWidget();

            void setResponse(domain::Response response);

        private:
            Ui::ResponseControllerWidget* ui;
    };
}