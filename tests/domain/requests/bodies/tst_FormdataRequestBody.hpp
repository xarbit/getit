#pragma once

#include <QtTest>
#include <string>
#include <map>

#include "domain/requests/bodies/FormdataRequestBody.hpp"

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
        Domain::Requests::FormdataRequestBody* testClass;
        std::map<std::string, std::string> testData;

};
