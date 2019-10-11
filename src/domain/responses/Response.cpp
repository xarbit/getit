#include "Response.hpp"

using namespace Domain::Responses;

Response::Response(std::string body,
                   std::list<std::pair<std::string, std::string>> headers):
    body(body),
    headers(headers)
{

}

Response::~Response()
{

}

std::string Response::getBody()
{
    return this->body;
}

std::list<std::pair<std::string, std::string>> Response::getHeaders()
{
    return this->headers;
}
