#pragma once

#include <string>
#include <cpprest/http_client.h>

#include "domain/Request.hpp"

namespace getit::domain
{
    class CppRestRequest: public Request
    {
        public:
            CppRestRequest(std::string method, std::string uri, web::http::client::http_client* client = nullptr);
            ~CppRestRequest();

            void send(std::function<void(Response response)> callback) override;

        private:
            web::http::client::http_client* client;
    };
}