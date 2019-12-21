#pragma once

#include <string>
#include <map>
#include <functional>

#include "domain/RequestBody.hpp"
#include "domain/Response.hpp"

namespace domain
{
    class Request
    {
        public:
            Request(std::string method, std::string host, std::string resource);
            ~Request();

            void addHeader(std::string header, std::string value);
            void setBody(RequestBody* body);
            void send(std::function<void(Response response)> callback);

        private:
            std::string buildHeaders();
            std::string buildHeader(std::string key, std::string value);

            std::string method;
            std::string host;
            std::string resource;
            std::map<std::string, std::string> headers;
            RequestBody* body;
    };
}