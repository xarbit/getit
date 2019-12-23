#include <string>
#include <catch2/catch.hpp>

#include "domain/RawRequestBody.hpp"

TEST_CASE("Test RawRequestBody", "[domain]")
{
    std::string defaultContentType = "text/plain;";
    std::string body = "My plain text body";

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

    SECTION("RawRequestBody returns expected size of the body")
    {
        // Arrange
        size_t expectedSize = body.size();
        auto request = new domain::RawRequestBody();

        // Act
        request->setBody(body);
        size_t result = request->getSize();

        // Assert
        REQUIRE(result == expectedSize);
    }

    SECTION ("RawRequestBody returns given body")
    {
        // Arrange
        auto request = new domain::RawRequestBody();

        // Act
        request->setBody(body);
        std::string result = request->getBody();

        // Assert
        REQUIRE(result == body);
    }
}