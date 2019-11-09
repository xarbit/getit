#pragma once

#include <string>
#include <initializer_list>

namespace Domain::Requests
{
    struct IRequestBody
    {
        public:
            ~IRequestBody() = default;

            virtual std::initializer_list<std::string> getBody() = 0;
    };
}