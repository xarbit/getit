#pragma once

#include <string>

namespace Domain
{
    class IHeader
    {
        public:
            virtual ~IHeader() = default;

            virtual std::string getSerialized();
    };
}
