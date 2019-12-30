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
    
    if (this->body == nullptr || this->body == NULL) {
        std::cout << "Body is null" << std::endl;
    }

    web::http::http_request request;
    request.set_body(this->body->getBody(), this->body->getContentType());
    request.set_method(this->method);

    std::cout << "After creating and setting request" << std::endl;

    for (auto const& [header, value]: this->headers) {
        request.headers().add(header, value);
    }

    std::cout << "After setting headers" << std::endl;

    this->client.request(request).then([=](web::http::http_response restResponse) {
        std::cout << restResponse.extract_string().get() << std::endl;
        // Response response;
        
        // response.body = restResponse.extract_string().get();
        // response.statusCode = restResponse.status_code();

        // for (auto const& [header, value]: restResponse.headers()) {
        //     response.headers.insert({header, value});
        // }

        // callback(response);
    });
}