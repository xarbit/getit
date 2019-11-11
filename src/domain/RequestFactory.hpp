#pragma once

#include "domain/HttpRequestLibrary.hpp"
#include "domain/Request.hpp"

namespace getit
{
    class RequestFactory
    {
        public:
            static Request getRequest(HttpRequestLibrary library);
    }
}