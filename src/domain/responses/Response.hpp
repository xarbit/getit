#pragma once

#include <list>
#include <string>

namespace Domain
{
    namespace Responses
    {
        class Response
        {
            public:
                Response(std::string body,
                         std::list<std::pair<std::string, std::string>> headers);
                ~Response();

                std::string getBody();
                std::list<std::pair<std::string, std::string>> getHeaders();

            private:
                std::string body;
                std::list<std::pair<std::string, std::string>> headers;
        };
    }
}
