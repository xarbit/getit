#include "domain/Request.hpp"

using namespace domain;

Request::Request(std::string method, std::string host, std::string resource):
    method(method),
    host(host),
    resource(resource)
{

}

Request::~Request()
{
    delete this->body;
}

void Request::addHeader(std::string header, std::string value)
{
    this->headers.insert(header, value);
}

void Request::setBody(RequestBody* body)
{
    this->body = body;
}

void Request::send(std::function<void(Response response)> callback)
{

}

std::string Request::buildHeaders()
{
    std::string start = this->method + this->resource + "HTTP 1.1\r\n";
    std::string hostHeader = this->buildHeader("Host", this->host);
    std::string lengthHeader = this->buildHeader("Content-Length", std::to_string(this->body->getSize()));
    std::string connectionHeader = this->buildHeader("Connection", "Keep-Alive");
    std::string contentTypeHeader = this->buildHeader("Content-Type", this->body->getContentTypeHeader());
    std::string acceptHeader = this->buildHeader("Accept-Charset", "utf-8");
    std::string customHeaders;

    for (auto const& [key, value]: this->headers) {
        customHeaders += this->buildHeader(key, value);
    }

    return start + hostHeader + lengthHeader + connectionHeader + contentTypeHeader + acceptHeader + customHeaders;
}

std::string buildHeader(std::string key, std::string value)
{
    return key + ": " + value + "\r\n";
}