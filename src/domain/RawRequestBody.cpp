#include "domain/RawRequestBody.hpp"

using namespace getit::domain;

RawRequestBody::RawRequestBody(std::string contentType):
    contentType(contentType)
{
    
}

RawRequestBody::RawRequestBody():
    RawRequestBody(DEF_CONTENT_TYPE)
{
    
}

RawRequestBody::~RawRequestBody()
{
    
}

void RawRequestBody::setContentType(std::string contentType)
{
    this->contentType = contentType;
}

void RawRequestBody::setBody(std::string body)
{
    this->body = body;
}

std::string RawRequestBody::getContentType()
{
    return this->contentType;
}

std::string RawRequestBody::getBody()
{
    return this->body;
}

size_t RawRequestBody::getSize()
{
    return this->body.size();
}