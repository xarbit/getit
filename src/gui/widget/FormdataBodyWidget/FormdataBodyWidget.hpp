#pragma once

#include <string>

#include "domain/FormdataRequestBody.hpp"
#include "domain/RequestBody.hpp"
#include "gui/widget/BodyWidget/Body.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class FormdataBodyWidget; }
QT_END_NAMESPACE

namespace getit::gui::widget
{
    class FormdataBodyWidget: public Body
    {
        Q_OBJECT
        
        public:
            FormdataBodyWidget(QWidget* parent = nullptr);
            ~FormdataBodyWidget();

            std::string getName() override;
            getit::domain::RequestBody* getRequestBody() override;

        private:
            Ui::FormdataBodyWidget* ui;

            static std::string generateBoundary();
            getit::domain::FormdataRequestBody body;
            const std::string name = "Formdata";
    };
}