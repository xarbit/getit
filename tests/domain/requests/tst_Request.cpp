#include "tst_Request.hpp"

#include <QSignalSpy>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

using namespace Domain::Requests;
using namespace Domain::Responses;

tst_Request::tst_Request()
{
    expectedError = QNetworkReply::NetworkError::NoError;
    expectedErrorString = "No error";
    expectedHeaders.append(QPair<QByteArray, QByteArray>("Authentication", "MySecretPass"));
    expectedData = QString("My network reply").toUtf8();

//    mockReply = new Mocks::MockQNetworkReply(expectedError, expectedErrorString, expectedHeaders, expectedData, this);
//    mockNetworkManager = new Mocks::MockQNetworkManager(mockReply, this);
//    testClass = new Request(mockNetworkManager);
    testClass = new Request(new QNetworkAccessManager(this));
}

tst_Request::~tst_Request()
{
    delete testClass;
    delete mockReply;
    delete mockNetworkManager;
}

void tst_Request::send()
{
    QObject::connect(testClass, &Request::requestSent, this, [=](Response* response) {
        auto result = response->getBody();
        QCOMPARE(expectedData.toStdString(), result);
//        QCOMPARE(1, 3);
    });

    QObject::connect(testClass, &Request::requestError, this, [=](std::string errorMessage) {
        QCOMPARE(expectedErrorString.toStdString(), errorMessage);
    });

    testClass->send(mockMethod, mockUri);
//    mockNetworkManager->emitFinished();
}
