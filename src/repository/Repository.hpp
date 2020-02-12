#pragma once

#include <string>

#include "domain/Request.hpp"

namespace getit::repository
{
    struct Repository
    {
        public:
            virtual ~Repository() = default;

            virtual void save(getit::domain::Request*) = 0;
            virtual getit::domain::Request* open(std::string) = 0;
    };
}
