#pragma once

#include <cpr/cpr.h>
#include <functional>
#include <map>
#include <string>

#include "domain/Request.hpp"
#include "domain/Response.hpp"

namespace getit
{
    class CprRequest: public Request
    {
        public:
            CprRequest(HttpRequestMethod requestMethod, std::string uri);
            ~CprRequest();

            void addHeader(std::string header, std::string value) override;
            void addCookie(std::string cookie, std::string value) override;
            void send(std::function<void(Response response)> callback) override;

        private:
            cpr::Session session;
            std::map<std::string, std::string> cookies;
            std::map<std::string, std::string> headers;
    };
}