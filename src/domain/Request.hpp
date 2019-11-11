#pragma once

#include <string>
#include "domain/RequestBody.hpp"

namespace getit
{
    template<typename HttpLibrary>
    class Request
    {
        public:
            Request(std::string method, std::string uri);
            ~Request();

            virtual void addHeader(std::string header, std::string value) = 0;
            virtual void addCookoie(std::string cookie, std::string value) = 0;
            virtual void setBody(RequestBody* body) = 0;

        private:
            std::string method;
            std::string uri;
            HttpLibrary httpLibrary;
            RequestBody body;
    };
}
