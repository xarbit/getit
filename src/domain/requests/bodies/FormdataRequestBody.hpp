#pragma once

#include <string>
#include <map>
#include <initializer_list>

#include "domain/requests/IRequestBody.hpp"

namespace Domain::Requests::Bodies
{
    class FormdataRequestBody: public IRequestBody
    {
        public:
            FormdataRequestBody(std::map<std::string, std::string>);
            ~FormdataRequestBody();

            std::initializer_list<std::string> getBody() override;

        private:
            std::map<std::string, std::string> formdata;
    };
}
