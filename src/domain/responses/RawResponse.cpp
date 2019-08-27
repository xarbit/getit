#include "domain/responses/RawResponse.hpp"

using namespace Domain::Responses;

RawResponse::RawResponse()
{

}

RawResponse::~RawResponse()
{

}

int RawResponse::getStatusCode()
{
    throw "Not implemented";
}

std::list<Domain::IHeader*> RawResponse::getHeaders()
{
    throw "Not implemented";
}

std::string RawResponse::getBody()
{
    throw "Not implemented";
}
