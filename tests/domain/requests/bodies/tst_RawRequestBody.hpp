#pragma once

#include <QTest>
#include <string>

#include "domain/requests/bodies/RawRequestBody.hpp"

class tst_RawRequestBody: public QObject
{
    public:
        tst_RawRequestBody();
        ~tst_RawRequestBody();

    private slots:
        void testGetBodyRetuurnsGivenValue();

    private:
        Domain::Requests::RawRequestBody* testClass;
        std::string testData;
};

