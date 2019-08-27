#include "domain/responses/JsonResponse.hpp"

using namespace Domain::Responses;

JsonResponse::JsonResponse()
{

}

JsonResponse::~JsonResponse()
{

}

int JsonResponse::getStatusCode()
{
    throw "Not implemented";
}

std::list<Domain::IHeader*> JsonResponse::getHeaders()
{
    throw "Not implemented";
}

std::string JsonResponse::getBody()
{
    throw "Not implemented";
}
