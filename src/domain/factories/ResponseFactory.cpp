#include "ResponseFactory.hpp"

using namespace Domain::Factories;
using namespace Domain::Responses;

ResponseFactory::ResponseFactory()
{

}

ResponseFactory::~ResponseFactory()
{

}

Domain::Responses::IResponse* ResponseFactory::getResponse(std::string responseType)
{
    if (responseType == "application/json")
    {
        return new JsonResponse();
    }
    else if (responseType == "application/xml" || responseType == "text/html")
    {
        return new XmlResponse();
    }
    else if (responseType == "text")
    {
        return new RawResponse();
    }

    throw Domain::Exceptions::ResponseNotSupportedException(responseType);
}
