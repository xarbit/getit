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
}