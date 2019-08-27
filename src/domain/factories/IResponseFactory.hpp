#pragma once

#include <string>

#include "domain/responses/IResponse.hpp"

namespace Domain
{
    namespace Factories
    {
        class IResponseFactory
        {
            public:
                virtual ~IResponseFactory() = default;

                virtual Domain::Responses::IResponse* getResponse(std::string responseType) = 0;
        };
    }
}
