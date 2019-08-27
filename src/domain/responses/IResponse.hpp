#pragma once

#include <string>
#include <list>

#include "domain/IHeader.hpp"

namespace Domain
{
    namespace Responses
    {
        class IResponse
        {
            public:
                virtual ~IResponse() = default;

                virtual int getStatusCode() = 0;
                virtual std::list<IHeader*> getHeaders() = 0;
                virtual std::string getBody() = 0;
        };
    }
}
