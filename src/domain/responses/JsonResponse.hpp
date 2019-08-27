#pragma once

#include <string>
#include <list>

#include "domain/IHeader.hpp"
#include "domain/responses/IResponse.hpp"

namespace Domain
{
    namespace Responses
    {
        class JsonResponse: public IResponse
        {
            public:
                explicit JsonResponse();
                ~JsonResponse();

                int getStatusCode();
                std::list<IHeader*> getHeaders();
                std::string getBody();
        };
    }
}
