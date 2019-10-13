#pragma once

#include <string>
#include <map>

#include "domain/requests/IRequestBody.hpp"

namespace Domain
{
    namespace Requests
    {
        class JsonRequestBody: public IRequestBody
        {
            public:
                JsonRequestBody(std::map<std::string, std::string>);
                ~JsonRequestBody();

                std::string getBody();

            private:
                std::map<std::string, std::string> jsonKeys;
        };
    }
}
