#include "domain/CppRestRequest.hpp"

using namespace getit::domain;

CppRestRequest::CppRestRequest(std::string method, std::string uri, web::http::client::http_client* client):
    Request(method, uri)
{
    if (client == nullptr) {
        client = new web::http::client::http_client(uri);
    }   
}

CppRestRequest::~CppRestRequest()
{
    delete this->client;
}

void CppRestRequest::send(std::function<void(Response response)> callback)
{
    std::string body = this->body->getBody();
    std::string contentType = this->body->getContentType();

    web::http::http_request request;
    request.set_body(body);
    request.set_method(this->method);

    request.headers.add("", "");
    

    this->client->request(request).then([=](web::http::http_response restResponse) {
        Response response;
        
        restResponse.extract_string().then([=](std::string body) {
            Response response;

            response.body = body;
            response.headers = restResponse.headers;
            response.statusCode = restResponse.status_code();

            callback(response);
        });
    });
}