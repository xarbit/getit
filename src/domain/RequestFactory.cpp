#include "domain/RequestFactory.hpp"

using namespace getit::domain;

RequestFactory::RequestFactory(std::string requestType):
    requestType(requestType)
{

}

RequestFactory::~RequestFactory()
{
    
}

Request* RequestFactory::getRequest(std::string method, std::string uri)
{
    return new CppRestRequest(method, uri);
}