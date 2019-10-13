#include "domain/requests/bodies/tst_FormdataRequestBody.hpp"

using namespace Domain::Requests;

tst_FormdataRequestBody::tst_FormdataRequestBody()
{
}

tst_FormdataRequestBody::~tst_FormdataRequestBody()
{
    testData.clear();
    delete testClass;
}

void tst_FormdataRequestBody::testGetBodyReturnsStringRepresentationOfGivenFormdataElements()
{
    // Arrange
    testData.insert(std::pair<std::string, std::string>("key1", "value1"));
    testData.insert(std::pair<std::string, std::string>("key2", "value2"));
    testData.insert(std::pair<std::string, std::string>("key3", "value3"));

    std::string expectedResult = "key1=value1&key2=value2&key3=value3";
    testClass = new FormdataRequestBody(testData);

    // Act
    std::string result = testClass->getBody();

    // Assert
    QCOMPARE(expectedResult, result);
}

void tst_FormdataRequestBody::testGetBodyReturnsEmptyStringWhenAnEmptyListOfFormdataElementsIsSet()
{
    // Arrange
    testData.clear();

    std::string expectedResult = "";
    testClass = new FormdataRequestBody(testData);

    // Act
    std::string result = testClass->getBody();

    // Assert
    QCOMPARE(expectedResult, result);
}
