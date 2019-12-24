#include "domain/Request.hpp"

using namespace getit::domain;

Request::Request(std::string method, std::string uri):
    method(method),
    uri(uri)
{

}

Request::~Request()
{
    delete this->body;
}

void Request::addHeader(std::string header, std::string value)
{
    this->headers.insert({header, value});
}

void Request::setBody(RequestBody* body)
{
    this->body = body;
}