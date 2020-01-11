#pragma once

#include <string>

#include "domain/FormdataRequestBody.hpp"
#include "domain/RequestBody.hpp"
#include "gui/RequestBody/BodyWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class FormdataRequestBodyWidget; }
QT_END_NAMESPACE

namespace getit::gui::requestbody
{
    class FormdataRequestBodyWidget: public BodyWidget
    {
        Q_OBJECT
        
        public:
            FormdataRequestBodyWidget(QWidget* parent = nullptr);
            ~FormdataRequestBodyWidget();

            std::string getName() override;
            getit::domain::RequestBody* getRequestBody() override;

        private:
            Ui::FormdataRequestBodyWidget* ui;

            static std::string generateBoundary();
            getit::domain::FormdataRequestBody body;
            const std::string name = "Formdata";
    };
}