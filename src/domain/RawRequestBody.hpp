#pragma once

#include <string>

#include "domain/RequestBody.hpp"

namespace domain
{
    class RawRequestBody: public RequestBody
    {
        public:
            RawRequestBody(std::string contentTypeHeader);
            RawRequestBody();
            ~RawRequestBody();

            void setBody(std::string body);
            
            std::string getContentTypeHeader() override;
            std::string getBody() override;
            size_t getSize() override;

        private:
            std::string contentTypeHeader;
            std::string body;

            inline static const std::string DEF_CONTENT_TYPE = "text/plain;";
    };
}