#pragma once

#include <QtTest>
#include <string>
#include <map>

#include "domain/requests/bodies/JsonRequestBody.hpp"

using namespace Domain::Requests;

class tst_JsonRequestBody: public QObject
{
        Q_OBJECT

    public:
        tst_JsonRequestBody();
        ~tst_JsonRequestBody();

    private slots:
        void testGetBodyReturnsStringJsonBodyRepresentationOfGivenElements();
        void testGetBodyReturnsEmptyJsonObjectWhenAListWithEmptyElementsIsGiven();

    private:
        Domain::Requests::JsonRequestBody* testClass;
        std::map<std::string, std::string> testData;
};
