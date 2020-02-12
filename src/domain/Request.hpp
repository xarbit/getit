#pragma once

#include <string>
#include <map>
#include <functional>

#include "domain/RequestBody.hpp"
#include "domain/Response.hpp"

namespace getit::domain
{
    class Request
    {
        public:
            Request(std::string method, std::string uri);
            virtual ~Request() = default;

            void addHeader(std::string header, std::string value);
            void addHeaders(std::map<std::string, std::string> headers);
            void setBody(RequestBody* body);
            virtual void send(std::function<void(Response* response)> callback) = 0;

        protected:
            std::string method;
            std::string uri;
            std::map<std::string, std::string> headers;
            RequestBody* body = nullptr;
    };
}
