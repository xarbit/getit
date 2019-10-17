#pragma once

#include <future>
#include <QTest>

#include "mocks/MockQNetworkManager.hpp"
#include "mocks/MockQNetworkReply.hpp"
#include "domain/requests/Request.hpp"
#include "domain/responses/Response.hpp"

class tst_Request: public QObject
{
        Q_OBJECT

    public:
        tst_Request();
        ~tst_Request();

    private slots:
        void send();

    private:
        Domain::Requests::Request* testClass;
        Mocks::MockQNetworkManager* mockNetworkManager;
        Mocks::MockQNetworkReply* mockReply;

        std::string mockMethod = "GET";
        std::string mockUri = "https:://wocoapp.nl/connect/api/v1/translations/fetch/NL";

        QNetworkReply::NetworkError expectedError;
        QString expectedErrorString;
        QList<QNetworkReply::RawHeaderPair> expectedHeaders;
        QByteArray expectedData;
};

