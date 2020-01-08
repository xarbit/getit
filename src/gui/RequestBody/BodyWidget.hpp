#pragma once

#include <string>
#include <QWidget>

#include "domain/RequestBody.hpp"

namespace getit::gui::requestbody
{
    struct BodyWidget: public QWidget
    {
        public:
            BodyWidget(QWidget* parent): QWidget(parent) {}
            virtual ~BodyWidget() = default;

            virtual std::string getName() = 0;
            virtual getit::domain::RequestBody* getRequestBody() = 0;
    };
}