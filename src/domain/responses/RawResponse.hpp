#pragma once

#include <string>
#include <list>

#include "domain/IHeader.hpp"
#include "domain/responses/IResponse.hpp"

namespace Domain
{
    namespace Responses
    {
        class RawResponse: public IResponse
        {
            public:
                explicit RawResponse();
                ~RawResponse();

                int getStatusCode();
                std::list<IHeader*> getHeaders();
                std::string getBody();
        };
    }
}
