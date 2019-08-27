#pragma once

#include <string>

#include "domain/IResponse.hpp"

namespace Domain {
    namespace Factories {
        class IResponseFactory {
            public:
                virtual ~IResponseFactory() = default;

                virtual Domain::IResponse getResponse(std::string responseType) = 0;
        };
    }
}
