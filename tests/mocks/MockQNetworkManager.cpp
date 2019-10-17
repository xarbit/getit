#include "MockQNetworkManager.hpp"

using namespace Mocks;

MockQNetworkManager::MockQNetworkManager(QNetworkReply* mockReply, QObject* parent):
    QNetworkAccessManager(parent),
    mockReply(mockReply)
{

}

MockQNetworkManager::~MockQNetworkManager()
{
    mockReply->deleteLater();
}

QNetworkReply* MockQNetworkManager::sendCustomRequest(const QNetworkRequest&, const QByteArray&, QIODevice*)
{
    return mockReply;
}

QNetworkReply* MockQNetworkManager::sendCustomRequest(const QNetworkRequest&, const QByteArray&, const QByteArray&)
{
    return mockReply;
}

QNetworkReply* MockQNetworkManager::sendCustomRequest(const QNetworkRequest&, const QByteArray&, QHttpMultiPart*)
{
    return mockReply;
}

void MockQNetworkManager::emitFinished()
{
    emit finished(mockReply);
}
