#pragma once

#include <string>

namespace domain
{
    struct RequestBody
    {
        public:
            virtual std::string getContentType() = 0;
            virtual size_t getSize() = 0;
            virtual std::string getBody() = 0;
    };
}
