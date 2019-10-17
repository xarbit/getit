#pragma once

#include <string>
#include <QNetworkReply>

namespace Mocks
{
    class MockQNetworkReply: public QNetworkReply
    {
        public:
            MockQNetworkReply(
                    QNetworkReply::NetworkError mockError,
                    QString mockErrorString,
                    QList<QNetworkReply::RawHeaderPair>& mockHeaders,
                    QByteArray mockData,
                    QObject* parent = nullptr);
            ~MockQNetworkReply() override;

            QNetworkReply::NetworkError error() const;
            QString errorString() const;
            QList<QNetworkReply::RawHeaderPair>& rawHeaderPairs() const;
            QByteArray readAll();
            qint64 read(char* data, qint64 maxSize);
            QByteArray read(qint64 maxSize);
            bool isOpen() const;

        protected:
            qint64 readData(char* data, qint64 maxSize) override;
            void abort() override;

        private:
            QNetworkReply::NetworkError mockError;
            QString mockErrorString;
            QList<QNetworkReply::RawHeaderPair>& mockHeaders;
            QByteArray mockData;
    };
}

