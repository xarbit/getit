#include "domain/requests/bodies/FormdataRequestBody.hpp"

using namespace Domain::Requests;

FormdataRequestBody::FormdataRequestBody(std::map<std::string, std::string> formdata):
    formdata(formdata)
{

}

FormdataRequestBody::~FormdataRequestBody()
{
    formdata.clear();
}

std::string FormdataRequestBody::getBody()
{
    std::string formdataString;

    for (auto const& iterator : this->formdata) {
        formdataString = formdataString
                .append(iterator.first)
                .append("=")
                .append(iterator.second)
                .append("&");
    }

    // Remove last ampersand
    formdataString.pop_back();

    return formdataString;
}
