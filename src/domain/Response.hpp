#pragma once

#include <map>
#include <string>

namespace getit
{
    struct Response
    {
        public:
            std::string body;
            std::map<std::string, std::string> headers;

            std::string getHeader(std::string name) {
                this->headers.find(name);
            }
    };
}