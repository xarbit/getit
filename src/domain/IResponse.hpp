#pragma once

#include <string>
#include <list>

#include "domain/IHeader.hpp"

namespace Domain {
    class IResponse {
        public:
            virtual ~IResponse() = default;

            virtual int getStatusCode();
            virtual std::list<IHeader*> getHeaders();
            virtual std::string getBody();
    };
}
