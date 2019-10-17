#pragma once

#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Mocks
{
    class MockQNetworkManager: public QNetworkAccessManager
    {
        public:
            MockQNetworkManager(QNetworkReply* mockReply, QObject* parent = nullptr);
            ~MockQNetworkManager();

            QNetworkReply* sendCustomRequest(const QNetworkRequest& request, const QByteArray& verb, QIODevice* data = nullptr);
            QNetworkReply* sendCustomRequest(const QNetworkRequest& request, const QByteArray& verb, const QByteArray& data);
            QNetworkReply* sendCustomRequest(const QNetworkRequest& request, const QByteArray& verb, QHttpMultiPart* multiPart);

            void emitFinished();

        private:
            QNetworkReply* mockReply;
    };
}

