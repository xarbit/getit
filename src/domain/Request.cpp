#include "domain/Request.hpp"

using namespace getit;

Request::Request(HttpRequestMethod requestMethod, std::string uri):
    requestMethod(requestMethod),
    uri(uri)
{
    
}

void Request::setBody(std::variant<std::list<FormdataElement>, std::string> body)
{
    this->body = body;

    // Get data from body

    if (auto raw = std::get_if<std::string>(&this->body)) {
        delete raw;
    } else if (auto formdata = std::get_if<std::list<FormdataElement>>(&this->body)) {

    }
}