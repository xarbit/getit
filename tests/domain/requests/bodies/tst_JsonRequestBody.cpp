#include "tst_JsonRequestBody.hpp"

using namespace Domain::Requests;

tst_JsonRequestBody::tst_JsonRequestBody()
{
}

tst_JsonRequestBody::~tst_JsonRequestBody()
{
    testData.clear();
    delete testClass;
}

void tst_JsonRequestBody::testGetBodyReturnsStringJsonBodyRepresentationOfGivenElements()
{
    // Arrange
    testData.insert(std::pair<std::string, std::string>("key1", "value1"));
    testData.insert(std::pair<std::string, std::string>("key2", "value2"));
    testData.insert(std::pair<std::string, std::string>("key3", "value3"));

    std::string expectedResult = "{\"key1\":\"value1\",\"key2\":\"value2\",\"key3\":\"value3\"}";
    testClass = new JsonRequestBody(testData);

    // Act
    std::string result = testClass->getBody();

    // Assert
    QCOMPARE(expectedResult, result);
}

void tst_JsonRequestBody::testGetBodyReturnsEmptyJsonObjectWhenAListWithEmptyElementsIsGiven()
{
    // Arrange
    testData.clear();

    std::string expectedResult = "{}";
    testClass = new JsonRequestBody(testData);

    // Act
    std::string result = testClass->getBody();

    // Assert
    QCOMPARE(expectedResult, result);
}
