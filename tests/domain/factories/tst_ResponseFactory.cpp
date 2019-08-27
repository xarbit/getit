#include <catch.hpp>

#include "domain/exceptions/ResponseNotSupportedException.hpp"
#include "domain/factories/ResponseFactory.hpp"
#include "domain/factories/IResponseFactory.hpp"
#include "domain/responses/IResponse.hpp"
#include "domain/responses/JsonResponse.hpp"
#include "domain/responses/RawResponse.hpp"
#include "domain/responses/XmlResponse.hpp"

using namespace Domain::Factories;
using namespace Domain::Responses;

TEST_CASE("ResponseFactory", "[domain]")
{
    IResponseFactory* factory       = new ResponseFactory();
    std::string invalidResponseType = "non_existing_response_type";
    std::string jsonResponseType    = "application/json";
    std::string xmlResponseType     = "application/xml";
    std::string htmlResponseType    = "text/html";
    std::string textResponseType    = "text";

    SECTION("returns a JsonResponse object when the response type is application/json")
    {
        IResponse* result = factory->getResponse(jsonResponseType);

        CHECK(dynamic_cast<JsonResponse*>(result));
    }

    SECTION("returns a XmlResponse object when the response type is application/xml")
    {
        IResponse* result = factory->getResponse(xmlResponseType);

        CHECK(dynamic_cast<XmlResponse*>(result));
    }

    SECTION("returns a XmlResponse object when the response type is text/html")
    {
        IResponse* result = factory->getResponse(htmlResponseType);

        CHECK(dynamic_cast<XmlResponse*>(result));
    }

    SECTION("returns a RawResponse object when the response type is text")
    {
        IResponse* result = factory->getResponse(textResponseType);

        CHECK(dynamic_cast<RawResponse*>(result));
    }

    SECTION("throws exception when the response type is unknown")
    {
        CHECK_THROWS(factory->getResponse(invalidResponseType));
    }
}
