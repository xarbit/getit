#pragma once

#include <string>
#include <map>

#include "domain/requests/IRequestBody.hpp"

namespace Domain
{
    namespace Requests
    {
        class FormdataRequestBody: public IRequestBody
        {
            public:
                FormdataRequestBody(std::map<std::string, std::string>);
                ~FormdataRequestBody();

                std::string getBody();

            private:
                std::map<std::string, std::string> formdata;
        };
    }
}
