#include "tst_RawRequestBody.hpp"

using namespace Domain::Requests;

tst_RawRequestBody::tst_RawRequestBody()
{

}

tst_RawRequestBody::~tst_RawRequestBody()
{
    delete testClass;
}

void tst_RawRequestBody::testGetBodyRetuurnsGivenValue()
{
    // Arrange
    testData = "<object><key1>value1</key1></object>";

    std::string expectedResult = testData;
    testClass = new RawRequestBody(testData);

    // Act
    std::string result = testClass->getBody();

    // Assert
    QCOMPARE(expectedResult, result);
}
