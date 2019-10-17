#include "MockQNetworkReply.hpp"

using namespace Mocks;

MockQNetworkReply::MockQNetworkReply(
        QNetworkReply::NetworkError mockError,
        QString mockErrorString,
        QList<QNetworkReply::RawHeaderPair>& mockHeaders,
        QByteArray mockData,
        QObject* parent):
    QNetworkReply(parent),
    mockError(mockError),
    mockErrorString(mockErrorString),
    mockHeaders(mockHeaders),
    mockData(mockData)
{

}

MockQNetworkReply::~MockQNetworkReply()
{
}

QNetworkReply::NetworkError MockQNetworkReply::error() const
{
    return mockError;
}

QString MockQNetworkReply::errorString() const
{
    return mockErrorString;
}

QList<QNetworkReply::RawHeaderPair>& MockQNetworkReply::rawHeaderPairs() const
{
    return mockHeaders;
}

QByteArray MockQNetworkReply::readAll()
{
    return mockData;
}


qint64 MockQNetworkReply::read(char*, qint64)
{
    return 0;
}

QByteArray MockQNetworkReply::read(qint64)
{
    return mockData;
}

bool MockQNetworkReply::isOpen() const
{
    return true;
}

qint64 MockQNetworkReply::readData(char*, qint64 maxSize)
{
    return maxSize;
}

void MockQNetworkReply::abort()
{
}
