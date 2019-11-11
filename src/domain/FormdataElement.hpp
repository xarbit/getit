#pragma once

#include <cstdio>
#include <string>
#include <variant>

namespace getit
{
    struct FormdataElement
    {
        public:
            std::string name;
            std::variant<std::string, std::FILE> value;
    };
}