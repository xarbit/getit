#include "domain/CprRequest.hpp"

using namespace getit;

CprRequest::CprRequest(HttpRequestMethod requestMethod, std::string uri):
    Request(requestMethod, uri)
{
    
}

CprRequest::~CprRequest()
{
    this->headers.clear();
    this->cookies.clear();
}

void CprRequest::addHeader(std::string header, std::string value)
{
    this->headers.insert(header, value);
}

void CprRequest::addCookie(std::string cookie, std::string value)
{
    this->cookies.insert(cookie, value);
}

void CprRequest::send(std::function<void(Response response)> callback)
{
    for (auto header: this->headers) {
        
    }

    // Get data from body
    if (auto raw = std::get_if<std::string>(&this->body)) {
        this->session.SetBody(cpr::Body(*raw));
    } else if (auto formdata = std::get_if<std::list<FormdataElement>>(&this->body)) {
        cpr::Multipart multipart(formdata->size);

        for (auto formdataElement: *formdata) {
            std::string name = formdataElement.name;

            if (auto stringValue = std::get_if<std::string>(&formdataElement.value)) {
                auto part = cpr::Part(name, *stringValue);
                multipart.parts.insert(multipart.parts.end(), part);
            } else if (auto fileValue = std::get_if<std::FILE>(&formdataElement.value)) {
                auto part = cpr::Part(name, cpr::File(*fileValue));
                multipart.parts.insert(multipart.parts.end(), part);
            }
        }

        this->session.SetMultipart(multipart);
    }

    this->session.SetUrl(this->uri);

    switch(this->requestMethod) {
        case HttpRequestMethod::DELETE:

        break;

        case HttpRequestMethod::GET:
        
        break;

        case HttpRequestMethod::HEAD:

        break;

        case HttpRequestMethod::OPTIONS:

        break;

        case HttpRequestMethod::PATCH:

        break;

        case HttpRequestMethod::POST:

        break;

        case HttpRequestMethod::PUT:

        break;
    }
}