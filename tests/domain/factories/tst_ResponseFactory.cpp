#include <catch.hpp>
#include <catch_trompeloeil.hpp>

#include "domain/exceptions/ResponseNotSupportedException.hpp"
#include "domain/factories/ResponseFactory.hpp"
#include "domain/factories/IResponseFactory.hpp"

extern template struct trompeloeil::reporter<trompeloeil::specialized>;

using namespace Domain::Factories;

TEST_CASE("ResponseFactory", "[domain]")
{
    IResponseFactory* factory       = new ResponseFactory();
    std::string invalidResponseType = "non_existing_response_type";

    SECTION("Throw exception when the response type isn't correct")
    {
        CHECK_THROWS(factory->getResponse(invalidResponseType));
    }
}
