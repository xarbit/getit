#include "domain/RawRequestBody.hpp"

using namespace domain;

#include <iostream>

RawRequestBody::RawRequestBody(std::string contentTypeHeader):
    contentTypeHeader(contentTypeHeader)
{
    
}

RawRequestBody::RawRequestBody():
    RawRequestBody(DEF_CONTENT_TYPE)
{
    
}

RawRequestBody::~RawRequestBody()
{
    
}

void RawRequestBody::setBody(std::string body)
{
    this->body = body;
}

std::string RawRequestBody::getContentTypeHeader()
{
    return this->contentTypeHeader;
}

std::string RawRequestBody::getBody()
{
    return this->body;
}

size_t RawRequestBody::getSize()
{
    return this->body.size();
}