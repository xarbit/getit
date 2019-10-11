#pragma once

#include <string>

#include "domain/requests/IRequestBody.hpp"

namespace Domain
{
    namespace Requests
    {
        struct RawRequestBody: public IRequestBody
        {
            public:
                RawRequestBody(std::string data);
                ~RawRequestBody();

                std::string getBody();

            private:
                std::string data;
        };
    }
}
