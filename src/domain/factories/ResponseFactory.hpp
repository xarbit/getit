#pragma once

#include <string>

#include "domain/factories/IResponseFactory.hpp"
#include "domain/exceptions/ResponseNotSupportedException.hpp"

namespace Domain {
    namespace Factories {
        class ResponseFactory: public IResponseFactory {
            public:
                ResponseFactory();
                ~ResponseFactory();

                Domain::IResponse getResponse(std::string responseType);
        };
    }
}

