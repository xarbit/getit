#include <QtTest>
#include <string>
#include <map>

// add necessary includes here
#include "domain/requests/bodies/FormdataRequestBody.hpp"

using namespace Domain::Requests;

class tst_FormdataRequestBody : public QObject
{
        Q_OBJECT

    public:
        tst_FormdataRequestBody();
        ~tst_FormdataRequestBody();

    private slots:
        void testGetBodyReturnsStringRepresentationOfGivenFormdataElements();
        void testGetBodyReturnsEmptyStringWhenAnEmptyListOfFormdataElementsIsSet();

    private:
         FormdataRequestBody* testClass;
         std::map<std::string, std::string> testData;

};

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
    testData.insert("key1", "value1");
    testData.insert("key2", "value2");
    testData.insert("key3", "value3");

    std::string expectedResult = "key1=value1&key2=value2&key3=value3";

    this->testClass = new FormdataRequestBody(this->testData);

    // Act
    std::string result = this->testClass->getBody();

    // Assert
    QCOMPARE(expectedResult, result);
}

void tst_FormdataRequestBody::testGetBodyReturnsEmptyStringWhenAnEmptyListOfFormdataElementsIsSet()
{
    // Arrange
    std::string expectedResult = "";
    this->testClass = new FormdataRequestBody(this->testData);

    // Act
    std::string result = this->testClass->getBody();

    // Assert
    QCOMPARE(expectedResult, result);
}

