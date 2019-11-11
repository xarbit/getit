#pragma once

#include <cpr/cpr.h>
#include <string>

#include "domain/Request.hpp"

namespace getit
{
    class CprRequest: public Request
    {
        public:
            CprRequest(HttpRequestMethod requestMethod, std::string uri);
            ~CprRequest();

            void addHeader(std::string header, std::string value) override;
            void addCookie(std::string cookie, std::string value) override;

        private:
            cpr::Session session;
    };
}