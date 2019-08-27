#pragma once

#include <string>

#include "domain/factories/IResponseFactory.hpp"
#include "domain/exceptions/ResponseNotSupportedException.hpp"
#include "domain/responses/JsonResponse.hpp"
#include "domain/responses/RawResponse.hpp"
#include "domain/responses/XmlResponse.hpp"

namespace Domain
{
    namespace Factories
    {
        class ResponseFactory: public IResponseFactory
        {
            public:
                ResponseFactory();
                ~ResponseFactory();

                Domain::Responses::IResponse* getResponse(std::string responseType);
        };
    }
}

