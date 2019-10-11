#pragma once

#include <string>

namespace Domain
{
    namespace Requests
    {
        struct IRequestBody
        {
            public:
                virtual ~IRequestBody() = default;

                virtual std::string getBody() = 0;
        };
    }
}
