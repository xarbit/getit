#pragma once

#include <string>
#include <QWidget>

#include "domain/RequestBody.hpp"

namespace getit::gui::widget
{
    struct Body: public QWidget
    {
        public:
            Body(QWidget* parent): QWidget(parent) {}
            virtual ~Body() = default;

            virtual std::string getName() = 0;
            virtual getit::domain::RequestBody* getRequestBody() = 0;
    };
}