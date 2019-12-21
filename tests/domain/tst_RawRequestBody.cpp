#define CATCH_CONFIG_MAIN

#include <string>
#include <catch2/catch.hpp>

#include "domain/RawRequestBody.hpp"

TEST_CASE("Test RawRequestBody", "[domain]")
{
    std::string defaultContentType = "text/plain;";

    SECTION("RawRequestBody returns correct content type header information")
    {
        // Arrange
        std::string contentType = "application/json;";
        auto request = new domain::RawRequestBody(contentType);

        // Act
        std::string result = request->getContentTypeHeader();

        // Assert
        REQUIRE(result == contentType);
    }

    SECTION("RawRequestBody returns default plain content type header when no explicit content type is given")
    {
        // Arrange
        auto request = new domain::RawRequestBody();

        // Act
        std::string result = request->getContentTypeHeader();

        // Assert
        REQUIRE(result == defaultContentType);
    }

    SECTION ("RawRequestBody returns given body")
    {
        // Arrange
        std::string body = "My plain text body";
        auto request = new domain::RawRequestBody();

        // Act
        request->setBody(body);
        std::string result = request->getBody();

        // Assert
        REQUIRE(result == body);
    }
}