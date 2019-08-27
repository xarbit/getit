#pragma once

#include <string>
#include <list>

#include "domain/IHeader.hpp"
#include "domain/responses/IResponse.hpp"

namespace Domain
{
    namespace Responses
    {
        class XmlResponse: public IResponse
        {
            public:
                explicit XmlResponse();
                ~XmlResponse();

                int getStatusCode();
                std::list<IHeader*> getHeaders();
                std::string getBody();
        };
    }
}
