#pragma once

#include <string>

namespace Domain
{
    class ICookie
    {
        public:
            virtual ~ICookie() = default;

            virtual std::string getSerialized();
    };
}
