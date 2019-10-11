#pragma once

#include <string>
#include <list>

#include "domain/requests/IRequestBody.hpp"

namespace Domain
{
    namespace Requests
    {
        class JsonRequestBody: public IRequestBody
        {
            public:
                JsonRequestBody(std::list<std::pair<std::string, std::string>>);
                ~JsonRequestBody();

                std::string getBody();

            private:
                std::list<std::pair<std::string, std::string>> jsonKeys;
        };
    }
}
