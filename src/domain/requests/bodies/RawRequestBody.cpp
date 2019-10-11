#pragma once

#include "domain/requests/bodies/RawRequestBody.hpp"

using namespace Domain::Requests;

RawRequestBody::RawRequestBody(std::string data):
    data(data)
{

}

RawRequestBody::~RawRequestBody()
{

}

std::string RawRequestBody::getBody()
{
    return this->data;
}
