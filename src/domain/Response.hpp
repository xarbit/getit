#pragma once

#include <map>
#include <string>

namespace getit::domain
{
    struct Response
    {
        public:
            int statusCode;
            std::map<std::string, std::string> headers;
            std::string body;
    };
}