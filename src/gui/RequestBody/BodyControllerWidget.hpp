#pragma once

#include <QTabWidget>
#include <vector>
#include <memory>

#include "gui/RequestBody/BodyWidget.hpp"
#include "gui/RequestBody/FormdataRequestBody/FormdataRequestBodyWidget.hpp"
#include "gui/RequestBody/RawRequestBody/RawRequestBodyWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class BodyControllerWidget; }
QT_END_NAMESPACE

namespace getit::gui::requestbody
{
    class BodyControllerWidget: public QTabWidget
    {
        Q_OBJECT

        public:
            BodyControllerWidget(QWidget* parent = nullptr);
            ~BodyControllerWidget();

        private:
            Ui::BodyControllerWidget* ui;

            const std::vector<BodyWidget*> bodies {
                new FormdataRequestBodyWidget(this),
                new RawRequestBodyWidget(this)
            };
    };
}
