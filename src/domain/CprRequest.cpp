#include "domain/CprRequest.hpp"

using namespace getit;

CprRequest::CprRequest(HttpRequestMethod requestMethod, std::string uri):
    Request(requestMethod, uri)
{
    
}

CprRequest::~CprRequest()
{

}

void CprRequest::addHeader(std::string header, std::string value)
{
    
}