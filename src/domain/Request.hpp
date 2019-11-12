#pragma once

#include <functional>
#include <list>
#include <string>
#include <variant>

#include "domain/FormdataElement.hpp"
#include "domain/HttpRequestMethod.hpp"
#include "domain/Response.hpp"

namespace getit
{
    class Request
    {
        public:
            Request(HttpRequestMethod requestMethod, std::string uri);
            virtual ~Request() = default;

            void setBody(std::variant<std::list<FormdataElement>, std::string>);
            virtual void addHeader(std::string header, std::string value) = 0;
            virtual void addCookie(std::string cookie, std::string value) = 0;
            virtual void send(std::function<void(Response response)> callback) = 0;

        protected:
            HttpRequestMethod requestMethod;
            std::string uri;
            std::variant<std::list<FormdataElement>, std::string> body;
    };
}