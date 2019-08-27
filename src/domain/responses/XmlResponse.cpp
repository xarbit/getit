#include "domain/responses/XmlResponse.hpp"

using namespace Domain::Responses;

XmlResponse::XmlResponse()
{

}

XmlResponse::~XmlResponse()
{

}

int XmlResponse::getStatusCode()
{
    throw "Not implemented";
}

std::list<Domain::IHeader*> XmlResponse::getHeaders()
{
    throw "Not implemented";
}

std::string XmlResponse::getBody()
{
    throw "Not implemented";
}
