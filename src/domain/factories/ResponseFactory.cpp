#include "ResponseFactory.hpp"

using namespace Domain::Factories;

ResponseFactory::ResponseFactory()
{

}

ResponseFactory::~ResponseFactory()
{

}

Domain::IResponse ResponseFactory::getResponse(std::string responseType)
{
    if (responseType == "application/json") {

    } else if (responseType == "application/xml") {

    }

    throw Domain::Exceptions::ResponseNotSupportedException(responseType);
}
