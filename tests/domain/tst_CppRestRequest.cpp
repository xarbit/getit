#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <map>
#include <string>

#include <cpprest/http_client.h>
#include <cpprest/http_listener.h>


#include "domain/CppRestRequest.hpp"
#include "domain/FormdataRequestBody.hpp"
#include "domain/RawRequestBody.hpp"

#include <iostream>

// Global variables
std::string header = "CustomHeader";
std::string headerValue = "CustomHeaderValue";

// Helper method to retrieve a uri with
// a given resource so the test cases
// don't block each other
std::string getUri(std::string resource)
{
    return "http://127.0.0.1:1874/" + resource;
}

// Helper method for sending a request, this also
// opens and closes the httpListener
void sendRequest(web::http::experimental::listener::http_listener* listener, getit::domain::CppRestRequest* request)
{
    listener->open().wait();

    request->send([=](getit::domain::Response response) {
        listener->close().wait();
    });
}

// Helper method to validate an expected header from
// the headers map given by CppRestSdk
bool validateHeader(web::http::http_headers headers, std::string expectedHeader, std::string expectedValue)
{
    for (auto const& [header, value]: headers) {
        if (header == expectedHeader) {
            return value == expectedValue;
        }
    }

    return false;
}

SCENARIO("Newly constructed CppRestRequest", "[domain]")
{
    WHEN("a GET request is being sent")
    {
        std::string uri = getUri("getHeadersTest");
        auto listener = new web::http::experimental::listener::http_listener(uri);
        auto request = new getit::domain::CppRestRequest("GET", uri);

        request->addHeader(header, headerValue);
        sendRequest(listener, request);

        THEN("the server receives a request with the correct headers and correct method")
        {
            listener->support(web::http::methods::GET, [=](web::http::http_request request) {
                REQUIRE(request.method() == "GET");
                REQUIRE(validateHeader(request.headers(), header, headerValue));

                request.reply(web::http::status_codes::Accepted);
            });
        }
    }

    WHEN("a POST request is being sent with a plain text body")
    {
        std::string uri = getUri("postRawDataBodyTest");
        auto listener = new web::http::experimental::listener::http_listener(uri);
        auto request = new getit::domain::CppRestRequest("POST", uri);

        std::string body = "My plain text body";
        auto requestBody = new getit::domain::RawRequestBody();
        requestBody->setBody(body);

        request->setBody(requestBody);
        sendRequest(listener, request);

        THEN("the server receives a request with a plain text body")
        {
            listener->support(web::http::methods::POST, [=](web::http::http_request request) {
                REQUIRE(body == request.extract_string().get());

                request.reply(web::http::status_codes::Accepted);
            });
        }
    }

    WHEN("a POST request is being sent with a formdata body")
    {
        std::string uri = getUri("postFormdataBodyTest");
        std::string element = "MyElement";
        std::string elementValue = "MyElementValue";
        std::string file = "file";
        std::string filePath = "tst_file.txt";
        std::string boundary = "-----**";
        std::string expectedContent = boundary + "\r\nContent-Disposition: form-data; name=\"" + element + "\"\r\n\r\n" + elementValue +"\r\n" + boundary + "\r\nContent-Disposition: form-data; name=\"" + file + "\"; filename=\"" + filePath + "\"\r\n\r\ncontent\r\n";
        auto listener = new web::http::experimental::listener::http_listener(uri);
        auto request = new getit::domain::CppRestRequest("POST", uri);
        auto requestBody = new getit::domain::FormdataRequestBody(boundary);

        requestBody->addElement(element, elementValue);
        requestBody->addFile(file, filePath);

        request->setBody(requestBody);
        sendRequest(listener, request);

        THEN("the server receives a multipart body")
        {
            listener->support(web::http::methods::POST, [=](web::http::http_request request) {
                std::string result = request.extract_string(true).get();

                REQUIRE(result == expectedContent);

                request.reply(web::http::status_codes::Accepted);
            });
        }
    }

    WHEN("a request is sent")
    {
        int statusCode = 234;
        std::string uri = getUri("testResponseStatusCodeForRequest");
        auto listener = new web::http::experimental::listener::http_listener(uri);
        auto request = new getit::domain::CppRestRequest("GET", uri);

        listener->open().wait();
        listener->support(web::http::methods::GET, [=](web::http::http_request request) {
            web::http::http_response response;
            response.set_status_code(statusCode);

            request.reply(response);
        });

        THEN("the response contains the status code given by the server")
        {
            request->send([=](getit::domain::Response response) {
                REQUIRE(response.statusCode == statusCode);

                listener->close().wait();
            });
        }
    }

    WHEN("a request is sent")
    {
        std::string header = "My-Header";
        std::string headerValue = "This is my custom header";
        std::string uri = getUri("testResponseHeadersForRequest");
        auto listener = new web::http::experimental::listener::http_listener(uri);
        auto request = new getit::domain::CppRestRequest("GET", uri);

        listener->open().wait();
        listener->support(web::http::methods::GET, [=](web::http::http_request request) {
            web::http::http_response response;
            response.headers().add(header, headerValue);

            request.reply(response);
        });

        THEN("the response contains the headers given by the server")
        {
            request->send([=](getit::domain::Response response) {
                for (auto const& [key, value]: response.headers) {
                    if (key == header) {
                        REQUIRE(value == headerValue);
                    }
                }

                listener->close().wait();
            });
        }
    }

    WHEN("a request is sent")
    {
        std::string responseBody = "My response body";
        std::string uri = getUri("testResponseBodyForRequest");
        auto listener = new web::http::experimental::listener::http_listener(uri);
        auto request = new getit::domain::CppRestRequest("GET", uri);

        listener->open().wait();
        listener->support(web::http::methods::GET, [=](web::http::http_request request) {
            web::http::http_response response;
            response.set_body(responseBody);

            request.reply(response);
        });

        THEN("the response contains the expected body given by the server")
        {
            request->send([=](getit::domain::Response response) {
                REQUIRE(response.body == responseBody);

                listener->close().wait();
            });
        }
    }
}
