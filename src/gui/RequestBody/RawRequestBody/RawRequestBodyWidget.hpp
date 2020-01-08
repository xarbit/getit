#pragma once

#include <string>

#include "domain/RawRequestBody.hpp"
#include "domain/RequestBody.hpp"
#include "gui/RequestBody/BodyWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class RawRequestBodyWidget; }
QT_END_NAMESPACE

namespace getit::gui::requestbody
{
    class RawRequestBodyWidget: public BodyWidget
    {
        Q_OBJECT

        public:
            RawRequestBodyWidget(QWidget* parent = nullptr);
            ~RawRequestBodyWidget();

            std::string getName() override;
            getit::domain::RequestBody* getRequestBody() override;

        private:
            Ui::RawRequestBodyWidget* ui;
            
            getit::domain::RawRequestBody body;
            const std::string name = "Raw";
    };
}