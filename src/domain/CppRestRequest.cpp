#include "domain/CppRestRequest.hpp"

using namespace getit::domain;

CppRestRequest::CppRestRequest(std::string method, std::string uri, web::http::client::http_client client):
    Request(method, uri),
    client(client)
{
    
}

CppRestRequest::CppRestRequest(std::string method, std::string uri):
    CppRestRequest(method, uri, web::http::client::http_client(uri))
{
    
}

CppRestRequest::~CppRestRequest()
{
    
}

void CppRestRequest::send(std::function<void(Response response)> callback)
{
    web::http::http_request request = this->buildRequest();  

    this->client.request(request).then([=](web::http::http_response restResponse) {
        Response response = this->buildResponse(restResponse);

        callback(response);
    });
}


web::http::http_request CppRestRequest::buildRequest()
{
    web::http::http_request request;
    request.set_method(this->method);

    this->addHeadersToRequest(&request);
    this->addBodyToRequest(&request);

    return request;
}

void CppRestRequest::addHeadersToRequest(web::http::http_request* request)
{
    for (auto const& [header, value]: this->headers) {
        request->headers().add(header, value);
    }
}

void CppRestRequest::addBodyToRequest(web::http::http_request* request)
{
    if (this->body != nullptr) {
        request->set_body(this->body->getBody(), this->body->getContentType());
    }
}

Response CppRestRequest::buildResponse(web::http::http_response restResponse)
{
    Response response;
        
    response.body = restResponse.extract_string().get();
    response.statusCode = restResponse.status_code();

    for (auto const& [header, value]: restResponse.headers()) {
        response.headers.insert({header, value});
    }

    return response;
}